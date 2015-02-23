//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@mit.edu
// 02/2015
//****************************************************************************
// main: FlexSEA-Execute
//****************************************************************************

// FlexSEA: Flexible & Scalable Electronics Architecture

//****************************************************************************
// Include(s)
//****************************************************************************

#include "main.h"

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow the usage of floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif

#ifdef USE_USB
	#warning "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
	#warning "   USB Enabled - Make sure to connect a cable!   "
	#warning "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
#endif

//****************************************************************************
// Local variable(s)
//****************************************************************************

//Misc. variables, used for debugging only
uint8 last_byte = 0;
int steps = 0, current_step = 0;
uint8_t tmp_rx_command_485_1[PAYLOAD_BUF_LEN];

//****************************************************************************
// External variable(s)
//****************************************************************************

//FlexSEA Network
extern unsigned char payload_str[];
extern unsigned char comm_str_payload[PAYLOAD_BUFFERS][PAYLOAD_BUF_LEN];
extern unsigned char comm_str[];

//Timer(s)
extern volatile uint8 t1_1ms_flag;
extern volatile uint8 t2_10ms_flag;
extern volatile uint8 t2_50ms_flag;

//ADC
extern volatile uint16 adc1_result;
extern volatile uint16 adc1_result_avg8;
extern unsigned char adc_sar1_flag;
extern unsigned int adc_res_filtered[ADC1_CHANNELS];

//RS-485:
extern volatile unsigned char uart2_flag;

//motor.c:
extern struct ctrl_s ctrl;

//peripherals.c
extern uint8 usb_success;

//DelSig ADC:
extern uint8 adc_delsig_flag;

extern uint8_t rx_command_485_1[PAYLOAD_BUF_LEN][PACKAGED_PAYLOAD_LEN];

//****************************************************************************
// Function(s)
//****************************************************************************

int main(void)
{
	//Local variables:
	int16 comm_res = 0, comm_success = 0;
	uint8 last_byte = 0, uart_buf_size = 0;
	uint8 i = 0;
	unsigned char result = 0;
	unsigned char comm_str_payload1[16];
	unsigned char ledr_state = 0, ledg_state = 0, ledb_state = 0;
	uint8 toggle_wdclk = 0;	
	uint8 cmd_ready_485_1 = 0;
	
	//Power on delay with LEDs
	power_on();
	
   	//Enable Global Interrupts
    CyGlobalIntEnable;        

	//Initialize all the peripherals
	init_peripherals();
	
	//Start with an empty buffer
	flexsea_clear_slave_read_buffer();	
	
	//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	//Test code - enable one and only one for special debugging
	//Normal code WILL NOT EXECUTE when this is enabled!
	//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	//strain_test_blocking();
	//safety_cop_comm_test_blocking();
	//imu_test_code_blocking();
	//motor_fixed_pwm_test_code_blocking(1000);
	//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

/*
	// ToDo remove
	//Sends one packet every 100ms
	//uint8 tbuf[8] = {1,2,3,4,5,250,251,252};
	uint8 tbuf[9] = {0,255,0,255,0,255,0,255, 0};
	uint8 val = 0, numb = 0;
	while(1)
	{
		//Generate the reply:
		tx_cmd_encoder_read_reply(FLEXSEA_MANAGE_1, 125);
		numb = comm_gen_str(payload_str, PAYLOAD_BUF_LEN);
		
		//Send it out:
		rs485_puts(comm_str, (numb+1));	
		
		CyDelay(1000);
	}
*/
	
	//Main loop
	while(1)
	{
		//1ms timebase
		if(t1_1ms_flag)
		{
			t1_1ms_flag = 0;
			
			EXP8_Write(1);	//Used to test the timing - can be removed	
			
			#ifdef USE_QEI1
				
			//Refresh encoder readings
			encoder_read();
				
			#endif	//USE_QEI1			
			
			#ifdef USE_TRAPEZ	
			
				if(ctrl.active_ctrl == CTRL_POSITION)
				{
					motor_position_pid(ctrl.position.setpoint_val, ctrl.position.actual_val);
				}
				else if(ctrl.active_ctrl == CTRL_IMPEDANCE)
				{
					//Impedance controller
					motor_impedance_encoder(ctrl.impedance.setpoint_val, ctrl.impedance.actual_val);
				}
			
			#endif	//USE_TRAPEZ
			
			//Refresh all the sensor data:
			update_sensors();
			
			//Alive LED
			alive_led();
			
			EXP8_Write(0);	//Used to test the timing - can be removed	
		}
		
		//10ms timebase
		if(t2_10ms_flag)
		{
			t2_10ms_flag = 0;
			
			#ifdef USE_TRAPEZ	
				
			if((ctrl.active_ctrl == CTRL_POSITION) || (ctrl.active_ctrl == CTRL_IMPEDANCE))
			{	
				//Trapezoidal trajectories (can be used for both Position & Impedance)				
				ctrl.position.setpoint_val = trapez_get_pos(steps);	//New setpoint
				//ToDo Move it to 1ms in the future (trapez.c will need to be updated first)
			}
			
			#endif	//USE_TRAPEZ	
			
			//If no controller is used the PWM should be 0:
			if(ctrl.active_ctrl == CTRL_NONE)
			{
				motor_open_speed_1(0);
			}
		}
		
		//50ms timebase for safety checks, etc
		if(t2_50ms_flag)
		{
			t2_50ms_flag = 0;
			
			dietemp_read();	//ToDo store in variable			
		}
				
		#ifdef USE_USB
			
			//USB Data
			if(usb_echo_blocking())
			{
				//Got new data in 
				//Try to decode
				comm_res = comm_decode_str();
				if(comm_res)
					comm_success = 1;
				
				//Toggle LEDR with new commands
				ledr_state ^= 1;
				LED_R_Write(ledr_state);
			}
			
		#endif	//USE_USB
		
		//RS-485 Byte Input
		#ifdef USE_RS485
			
			//UART2 (RS485)
			if(uart2_flag)
			{
				uart2_flag = 0;
				
				uart_buf_size = UART_2_GetRxBufferSize();
				if(uart_buf_size > 0)
				{
					for(i = 0; i < uart_buf_size; i++)
					{
						last_byte = UART_2_GetChar();	//It's a shame but there is no gets function
						update_rx_buf_byte_485_1(last_byte);
					}
				}
				
				//Got new data in, try to decode
				cmd_ready_485_1 = unpack_payload_485_1();
			}
			
		#endif	//USE_RS485
		
		//FlexSEA Network Communication
		#ifdef USE_COMM
			
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
				
				//Toggle LED1 with new commands
				ledb_state ^= 1;
				LED_B_Write(ledb_state);
			}
		
		#endif	//USE_COMM
		
		//SAR ADC results ready to be filtered?
		if(adc_sar1_flag)
		{
			adc_sar1_flag = 0;
			filter_adc();
		}
		
		//DelSig ADC results ready to be filtered?
		if(adc_delsig_flag)
		{
			adc_delsig_flag = 0;
			strain_filter();
		}
		
		//WatchDog Clock (Safety-CoP)
		toggle_wdclk ^= 1;
		WDCLK_Write(toggle_wdclk);
	}
}
