//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@media.mit.edu
// 02/2016
//****************************************************************************
// ext_input: External Input Devices/Sensors
//****************************************************************************

//****************************************************************************
// Include(s)
//****************************************************************************

#include "main.h"
#include "ext_input.h"

//****************************************************************************
// Variable(s)
//****************************************************************************

//Encoder:
struct enc_s encoder;

//Magnetic encoder, AS5047:
uint16 spidata_mosi[WORDS_IN_FRAME] = {0,0,0,0,0,0,0};
uint16 spidata_miso[WORDS_IN_FRAME] = {0,0,0,0,0,0,0};
uint16 spidata_mosi2[WORDS_IN_FRAME];
uint8 spistatus = 0;
uint16 angleunc = 0;

//Magnetic encoder, AS5048B:
uint8 as5048b_bytes[10] = {0,0,0,0,0,0,0,0,0,0};
uint8 as5048b_agc = 0, as5048b_diag = 0;
uint16 as5048b_mag = 0, as5048b_angle = 0;

//6-ch Strain Amplifier:
uint16 ext_strain[6] = {0,0,0,0,0,0};
uint8 ext_strain_bytes[12];
volatile uint8 i2c_0_r_buf[24];

//****************************************************************************
// Private Function Prototype(s):
//****************************************************************************	

static uint16 add_even_parity_msb(uint16 word);

//****************************************************************************
// Public Function(s)
//****************************************************************************

//Initialize the quadrature encoder input (QEI) 
void init_qei(void)
{
	QuadDec_1_Start();
	QuadDec_1_Enable();
	QuadDec_1_SetCounter(QUAD1_INIT);
}

//Updates the structure with the latest encoder value
int32 encoder_read(void)
{
	//Count: actual, last, difference
	encoder.count_last = encoder.count;
	encoder.count = QuadDec_1_GetCounter();
	encoder.count_dif = encoder.count - encoder.count_last;
	
	//For the position & impedance controllers we use the last count
	ctrl.position.pos = encoder.count;
	ctrl.impedance.actual_val = encoder.count;
	
	return encoder.count;
}
//Warning: encoder.count seems to be interpreted as a uint... casting (int32) before using it works.

//Updates the structure with the desired value and write it to the encoder
void encoder_write(int32 enc)
{
	encoder.count = enc;
	QuadDec_1_SetCounter(enc);
}

void init_as5047(void)
{
	//Init SPIM module:
    SPIM_1_Start();
}

//Read a single word
uint16 as5047_read_single(uint16 reg)
{
	//Clear buffers to start in a known state:
	SPIM_1_ClearTxBuffer();
	SPIM_1_ClearRxBuffer();
    CyDelayUs(10);

	//Send 1st byte (reg addr)
	spidata_mosi2[0] = add_even_parity_msb(AS5047_READ | reg);
	SPIM_1_PutArray(spidata_mosi2, 1);	
	CyDelayUs(10);
    spidata_miso[0] = SPIM_1_ReadRxData();
	
	//Send 2nd byte (empty, used to read)
	spidata_mosi2[0] = add_even_parity_msb(AS5047_READ | AS5047_REG_NOP);
	SPIM_1_PutArray(spidata_mosi2, 1);	
	CyDelayUs(10);
    spidata_miso[1] = SPIM_1_ReadRxData();	
	
	//spidata_miso[1] contains the answer. Remove parity and return value
	//ToDo: ignore word if wrong parity

	last_as5047_word = (spidata_miso[1] & 0x3FFF);
	return last_as5047_word;
}

//Manual I2C [Write - Restart - Read n bytes] function
//Takes around xus (400kHz) to run, then the ISR takes care of everything.
int strain_6ch_read(uint8 internal_reg_addr, uint8 *pData, uint16 length)
{
	uint8 status = 0, i = 0;
	
	//Currently having trouble detecting the flags to know when data is ready.
	//For now I'll transfer the previous buffer.
	for(i = 0; i < length; i++)
	{
		pData[i] = i2c_0_r_buf[i];
	}
	
	//Clear status:
	//I2C_1_MasterClearStatus();
	
	//Start, address, Write mode
	status = I2C_0_MasterSendStart(I2C_SLAVE_ADDR_6CH, 0);		
	if(status != I2C_0_MSTR_NO_ERROR)
		return 1;
	
	//Write to register
	status = I2C_0_MasterWriteByteTimeOut(internal_reg_addr, 500);
	if(status != I2C_0_MSTR_NO_ERROR)
	{
		//Release bus:
		I2C_0_BUS_RELEASE;
		
		return 2;
	}

	//Repeat start, read then stop (all by ISR):
	I2C_0_MasterReadBuf(I2C_SLAVE_ADDR_6CH, (uint8 *)i2c_0_r_buf, length, (I2C_0_MODE_COMPLETE_XFER | I2C_0_MODE_REPEAT_START));
	
	return 0;
}

//Manual I2C [Write - Restart - Read n bytes] function
//Takes around xus (400kHz) to run, then the ISR takes care of everything.
int as5048b_read(uint8 internal_reg_addr, uint8 *pData, uint16 length)
{
	uint8 status = 0, i = 0;
	
	//Currently having trouble detecting the flags to know when data is ready.
	//For now I'll transfer the previous buffer.
	for(i = 0; i < length; i++)
	{
		pData[i] = i2c_0_r_buf[i];
	}
	
	//Clear status:
	//I2C_1_MasterClearStatus();
	
	//Start, address, Write mode
	status = I2C_0_MasterSendStart(I2C_ADDR_AS5048B, 0);		
	if(status != I2C_0_MSTR_NO_ERROR)
		return 1;
	
	//Write to register
	status = I2C_0_MasterWriteByteTimeOut(internal_reg_addr, 500);
	if(status != I2C_0_MSTR_NO_ERROR)
	{
		//Release bus:
		I2C_0_BUS_RELEASE;
		
		return 2;
	}

	//Repeat start, read then stop (all by ISR):
	I2C_0_MasterReadBuf(I2C_ADDR_AS5048B, (uint8 *)i2c_0_r_buf, length, (I2C_0_MODE_COMPLETE_XFER | I2C_0_MODE_REPEAT_START));
	
	return 0;
}

//Reassembles the bytes we read in words
void strain_6ch_bytes_to_words(void)
{
	ext_strain[0] = ((((uint16)ext_strain_bytes[0] << 8) & 0xFF00) | (uint16)ext_strain_bytes[1]);
	ext_strain[1] = ((((uint16)ext_strain_bytes[2] << 8) & 0xFF00) | (uint16)ext_strain_bytes[3]);
	ext_strain[2] = ((((uint16)ext_strain_bytes[4] << 8) & 0xFF00) | (uint16)ext_strain_bytes[5]);
	ext_strain[3] = ((((uint16)ext_strain_bytes[6] << 8) & 0xFF00) | (uint16)ext_strain_bytes[7]);
	ext_strain[4] = ((((uint16)ext_strain_bytes[8] << 8) & 0xFF00) | (uint16)ext_strain_bytes[9]);
	ext_strain[5] = ((((uint16)ext_strain_bytes[10] << 8) & 0xFF00) | (uint16)ext_strain_bytes[11]);
}

//****************************************************************************
// Private Function(s)
//****************************************************************************

//When writing to the AS5047, MSB has to be an Even parity bit
static uint16 add_even_parity_msb(uint16 word)
{
	uint16 ret = 0;
	
	//__builtin_parity() returns 0 for even, 1 for odd
	// MSB = 1 when it's odd
	if(__builtin_parity((int)word))
	{
		ret = (word | PARITY_1);
	}
	else
	{
		ret = (word & PARITY_0);
	}
	
	return ret;
}

//****************************************************************************
// Test Function(s) - Use with care!
//****************************************************************************

void as5047_test_code_blocking(void)
{
    //uint8 i = 0;
   
    //Init SPIM module:
    SPIM_1_Start();
    CyDelay(10);   
	
    //Build the mosi packet:
    spidata_mosi[0] = add_even_parity_msb(AS5047_READ | AS5047_REG_ERRFL);
    spidata_mosi[1] = add_even_parity_msb(AS5047_READ | AS5047_REG_PROG);
    spidata_mosi[2] = add_even_parity_msb(AS5047_READ | AS5047_REG_DIAAGC);
    spidata_mosi[3] = add_even_parity_msb(AS5047_READ | AS5047_REG_MAG);
    spidata_mosi[4] = add_even_parity_msb(AS5047_READ | AS5047_REG_ANGLEUNC);
    spidata_mosi[5] = add_even_parity_msb(AS5047_READ | AS5047_REG_ANGLECOM);
    spidata_mosi[6] = add_even_parity_msb(AS5047_READ | AS5047_REG_NOP);
    
    while(1)
    {
		//Read all the fields:
		/*
		SPIM_1_ClearTxBuffer();
		SPIM_1_ClearRxBuffer();
        CyDelay(1);
       
        for(i = 0; i < WORDS_IN_FRAME ; i++)
        {
			spidata_mosi2[0] = spidata_mosi[i];
			SPIM_1_PutArray(spidata_mosi2, 1);
			
			CyDelayUs(15);
            spidata_miso[i] = SPIM_1_ReadRxData();
        }
        CyDelay(4);
       
        //Notes: delays only present for early debugging. Minimize/remove.
       
        //We could commutate the motor here.
		*/
		
		//Single word:
		angleunc = as5047_read_single(AS5047_REG_ANGLEUNC);
    }
}

void strain_amp_6ch_test_code_blocking(void)
{
	while(1)
	{
		strain_6ch_read(MEM_R_CH1_H, ext_strain_bytes, 12);
		strain_6ch_bytes_to_words();
		CyDelay(100);
	}
}

void as5048b_test_code_blocking(void)
{
	while(1)
	{
		as5048b_read(AD5048B_REG_AGC, as5048b_bytes, 6);
		
		as5048b_agc = as5048b_bytes[0];
		as5048b_diag = as5048b_bytes[1] & 0x0F;
		as5048b_mag = (as5048b_bytes[2]<<6) + (as5048b_bytes[3]&0x3F); 
		as5048b_angle = (as5048b_bytes[4]<<6) + (as5048b_bytes[5]&0x3F);
		
		CyDelay(100);
	}
}
