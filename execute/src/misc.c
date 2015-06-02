//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@mit.edu
// 02/2015
//****************************************************************************
// misc: when it doesn't belong in any another file, it ends up here...
//****************************************************************************

//Note: It's a sign that code is misplaced when this file gets long.

//****************************************************************************
// Include(s)
//****************************************************************************

#include "main.h"
#include "misc.h"

//****************************************************************************
// Variable(s)
//****************************************************************************

uint8 i2c_last_request = 0;

//Timers:
volatile uint8 t1_100us_flag = 0;
volatile uint8 t1_time_share = 0, t1_new_value = 0;

//ADC:
uint8 adc_sar1_flag = 0;
volatile uint8 adc_delsig_flag = 0;

//UART:
volatile uint8 data_ready_485_1 = 0;

//USB:
volatile uint8 data_ready_usb = 0;

//MinM RGB:
uint8 minm_rgb_color = 0, last_minm_rgb_color = 0;
uint8 minm_i2c_buf[MINM_BUF_SIZE];

//****************************************************************************
// Private Function Prototype(s):
//****************************************************************************


//****************************************************************************
// Public Function(s)
//****************************************************************************

//Write to MinM RGB LED
void i2c_write_minm_rgb(uint8 cmd, uint8 r, uint8 g, uint8 b)
{	
	// Write data to the slave : address pointer
	minm_i2c_buf[0] = cmd;
	minm_i2c_buf[1] = r;
	minm_i2c_buf[2] = g;
	minm_i2c_buf[3] = b;
	
	I2C_2_MasterClearStatus();
	//I2C_2_MasterClearWriteBuf();
    I2C_2_MasterWriteBuf(I2C_SLAVE_ADDR_MINM, (uint8 *) minm_i2c_buf,
                             4, I2C_2_MODE_COMPLETE_XFER);

	//ISR will take it from here...
	
	return;	
}

//One byte encodes the colors: 0 = Off, 1 = Red, 2 = Green, 3 = Blue, 4 = White
void minm_byte_to_rgb(uint8 byte, uint8 *r, uint8 *g, uint8 *b)
{
	switch(byte)
	{
		case 0:	//Off (black)
			(*r) = 0; (*g) = 0; (*b) = 0; 
			break;
		case 1:	//Red
			(*r) = 255; (*g) = 0; (*b) = 0; 
			break;
		case 2:	//Green
			(*r) = 0; (*g) = 255; (*b) = 0; 
			break;
		case 3:	//Blue
			(*r) = 0; (*g) = 0; (*b) = 255; 
			break;
		case 4:	//White
			(*r) = 255; (*g) = 255; (*b) = 255; 
			break;
		default:
			(*r) = 0; (*g) = 0; (*b) = 0; 
			break;
	}
}

//Updates the MinM LED if the color changed, otherwise does noting
void update_minm_rgb(void)
{
	static uint8 r = 0, g = 0, b = 0;
	
	#ifdef USE_I2C_EXT
	
	if(minm_rgb_color != last_minm_rgb_color)
	{
		//Color changed.
		
		minm_byte_to_rgb(minm_rgb_color, &r, &g, &b);
		i2c_write_minm_rgb(SET_RGB, r, g, b);
	}
	
	last_minm_rgb_color = minm_rgb_color;
	
	#endif	//USE_I2C_EXT
}

//Use this to test your RGB hardware
void minm_test_code(void)
{
	static uint16 rgb_test_code = 0;
	
	rgb_test_code++;
	if(rgb_test_code < 100)
		i2c_write_minm_rgb(SET_RGB, 255, 0, 0);
	else if((rgb_test_code >= 100) && (rgb_test_code <= 200))
		i2c_write_minm_rgb(SET_RGB, 0, 255, 0);
	else
		i2c_write_minm_rgb(SET_RGB, 0, 0, 255);
		
	if(rgb_test_code > 300)
		rgb_test_code = 0;
}

void alive_led(void)
{
	static uint8 toggle0 = 1, count0 = 0;
	
	//Fast blinking - Alive LED
	count0++;
	if(count0 >= ALIVE_HALF_T)
	{
		count0 = 0;
		toggle0^=1;
		LED_HB_Write(toggle0);
	}
}

//Power On Delay with LEDs
void power_on(void)
{
	set_led_rgb(1,0,0);
	CyDelay(250);
	set_led_rgb(0,1,0);
	CyDelay(250);
	set_led_rgb(0,0,1);
	CyDelay(250);
	set_led_rgb(0,0,0);
	CyDelay(250);
}

void set_led_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	//No fading, we use 1 or 0 for now. Flipping the sign so x = 1 means ON

	LED_R_Write((r & 0x01)^1);
	LED_G_Write((g & 0x01)^1);
	LED_B_Write((b & 0x01)^1);
}

//Call this function every ms in main while()
void rgb_led_ui(uint8_t err_l0, uint8_t err_l1, uint8_t err_l2, uint8_t new_comm)
{
	static uint32_t cnt_comm = UI_COMM_TIMEOUT, cnt_err_l0 = 0, cnt_err_l1 = 0, cnt_flash = 0;
	static uint8_t latch_err_l2 = 0, flash_red = 0, comm_blue = 0;
	uint8_t r = 0, g = 0, b = 0;

	//Set variable for the flashing red light:
	if(cnt_flash < UI_RED_FLASH_ON)
	{
		flash_red = 1;
	}
	else
	{
		flash_red = 0;
	}

	cnt_flash++;
	if(cnt_flash >= UI_RED_FLASH_PERIOD)
	{
		cnt_flash = 0;
	}

	//New communication green/blue:
	if(new_comm)
	{
		//Received a new valid packet, resets the counter
		cnt_comm = UI_COMM_TIMEOUT;
	}

	if(cnt_comm > 0)
		cnt_comm--;

	if(!cnt_comm)
	{
		comm_blue = 1;
	}
	else
	{
		comm_blue = 0;
	}

	//From the highest priority to the lowest:
	//=======================================

	if((err_l2 == 1) || (latch_err_l2 == 1))
	{
		//Major error => flashing red

		latch_err_l2 = 1;	//Latching it, will require a reset to be normal again
		r = flash_red;
		g = 0;
		b = 0;
	}
	else
	{
		if(err_l1 == 1)
		{
			//Intermediate error => Steady Red
			r = 1;
			g = 0;
			b = 0;
		}
		else
		{
			if(err_l0 == 1)
			{
				//Software error => Steady Yellow
				r = 1;
				g = 1;
				b = 0;
			}
			else
			{
				if(comm_blue == 1)
				{
					//Communication timeout, blue
					r = 0;
					g = 0;
					b = 1;
				}
				else
				{
					//Normal, green
					r = 0;
					g = 1;
					b = 0;
				}
			}
		}
	}

	//Assign the color to the RGB LED:
	set_led_rgb(r, g, b);
}

//How long does it take to run X function? Use this code and a scope to find out.
#define SDELAY	5
void timing_test_blocking(void)
{
	//Disable Global Interrupts
    CyGlobalIntDisable; 
	
	while(1)
	{
		//Synch sequence
		EXP9_Write(1);
		EXP8_Write(0);
		EXP8_Write(1);
		EXP8_Write(0);
		EXP8_Write(1);
		EXP8_Write(0);
		
		CyDelayUs(SDELAY);
		
		//Motor current PID
		EXP8_Write(1);
		motor_current_pid(ctrl.current.setpoint_val, ctrl.current.actual_val);
		EXP8_Write(0);
		
		//Motor current PID #2
		EXP8_Write(1);
		motor_current_pid_2(ctrl.current.setpoint_val, ctrl.current.actual_val);
		EXP8_Write(0);
		
		//Exit sequence:
		EXP9_Write(0);
		CyDelayUs(10*SDELAY);
		
		/*
		
		//SAR ADC filter
		EXP8_Write(1);
		filter_adc();
		EXP8_Write(0);
		
		//DelSig ADC filter
		EXP8_Write(1);
		strain_filter_dma();
		EXP8_Write(0);
		
		//Unpack payload (no data in the buffer)
		EXP8_Write(1);
		unpack_payload_485_1();
		EXP8_Write(0);
		
		//Exit sequence:
		EXP9_Write(0);
		CyDelayUs(10*SDELAY);
		*/
		
		/*
		//Position controller
		EXP8_Write(1);
		motor_position_pid(ctrl.position.setpoint_val, ctrl.position.actual_val);
		EXP8_Write(0);
		
		CyDelayUs(SDELAY);
		
		//Impedance controller:
		EXP8_Write(1);
		motor_impedance_encoder(ctrl.impedance.setpoint_val, ctrl.impedance.actual_val);
		EXP8_Write(0);
		
		CyDelayUs(SDELAY);
		
		//RGB LED UI:
		EXP8_Write(1);
		rgb_led_ui(1, 1, 1, 1);
		EXP8_Write(0);

		//Exit sequence:
		EXP9_Write(0);
		CyDelayUs(10*SDELAY);
		*/
		
		/*
		filter_adc();
		
		strain_filter_dma();
		*/
		
		/*
		unpack_payload_485_1();
	
		//Valid communication from RS-485 #1?
		if(cmd_ready_485_1 != 0)
		{
			cmd_ready_485_1 = 0;
			
			//Cheap trick to get first line	//ToDo: support more than 1
			for(i = 0; i < PAYLOAD_BUF_LEN; i++)
			{
				tmp_rx_command_485_1[i] = rx_command_485_1[0][i];
			}
			
			//payload_parse_str() calls the functions (if valid)
			result = payload_parse_str(tmp_rx_command_485_1);
			
			//LED:
			new_cmd_led = 1;
		}
		*/
	}
	
}

void init_sine_gen(void)
{
	VDAC8_2_Start();
}

uint16 output_sine(void)
{
	static double angle = 0;
	static double ret = 0;
	uint8 output = 0;
	
	//if(t1_new_value == 1)
	{	
		//t1_new_value = 0;
		
		angle += STEP;
		if(angle >= (2*PI))
			angle = 0;
		ret = sin(angle) + 1;
		
		output = (uint8)(ret*127);
		
		//Output on DAC:
		VDAC8_2_SetValue(output);
		
		CyDelayUs(DELAY);
	}	
	
	return output;
}

uint16 output_arb(void)
{
	static double angle = 0;
	static double ret = 0;
	static uint8 output = 0;
	static int16 i = 0;
	
	i++;
	
	//Slow ramp-up
	if(i < 100)
		output = i;
	
	//Fast ramp-down
	if(i >= 100 && i <= 150)
		output -= 2;
	
	//Castellation
	if(i > 150 && i <= 160)
		output = 255;
	if(i > 160 && i <= 170)
		output = 0;
	if(i > 180 && i <= 190)
		output = 255;
	if(i > 190 && i <= 200)
		output = 0;
	if(i > 200 && i <= 210)
		output = 255;

	if(i > 210)
	{
		angle += STEP;
		if(angle >= (2*PI))
		{
			angle = 0;
			i = 0;
		}
		ret = sin(angle) + 1;		
		output = (uint8)(ret*127);
	}
	
	//Output on DAC:
	VDAC8_2_SetValue(output);	
	
	CyDelayUs(DELAY);
	
	return output;
}

//Use this to test the current controller
void test_current_tracking_blocking(void)
{
	init_sine_gen();
	ctrl.active_ctrl = CTRL_CURRENT;
	ctrl.current.gain.I_KP = 30;
	ctrl.current.gain.I_KI = 25;
	Coast_Brake_Write(0);	//Coast
	
	uint16 val = 0;
	while(1)
	{
		val = output_sine();
		//val = output_arb();
		ctrl.current.setpoint_val = val*2 + 125;
	}
}

//Associate data with the right structure. We need that because of the way the ISR-based
//I2C works (we always get data from the last request)
void assign_i2c_data(uint8 *newdata)
{
	uint16 tmp = 0;
	
	if(i2c_last_request == I2C_RQ_GYRO)
	{
		//Gyro X:
		tmp = ((uint16)newdata[0] << 8) | ((uint16) newdata[1]);
		imu.gyro.x = (int16)tmp;
		
		//Gyro Y:
		tmp = ((uint16)newdata[2] << 8) | ((uint16) newdata[3]);
		imu.gyro.y = (int16)tmp;
		
		//Gyro Z:
		tmp = ((uint16)newdata[4] << 8) | ((uint16) newdata[5]);
		imu.gyro.z = (int16)tmp;		
	}
	else if(i2c_last_request == I2C_RQ_ACCEL)
	{
		//Accel X:
		tmp = ((uint16)newdata[0] << 8) | ((uint16) newdata[1]);
		imu.accel.x = (int16)tmp;
		
		//Accel Y:
		tmp = ((uint16)newdata[2] << 8) | ((uint16) newdata[3]);
		imu.accel.y = (int16)tmp;
		
		//Accel Z:
		tmp = ((uint16)newdata[4] << 8) | ((uint16) newdata[5]);
		imu.accel.z = (int16)tmp;		
	}
	else if(i2c_last_request == I2C_RQ_SAFETY)
	{
		safety_cop.status1 = newdata[0];
		safety_cop.status2 = newdata[1];
	}
}


//****************************************************************************
// Private Function(s)
//****************************************************************************
