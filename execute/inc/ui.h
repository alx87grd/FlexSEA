//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@mit.edu
// 09/2015
//****************************************************************************
// UI: User Interface related 
//****************************************************************************
	
#ifndef INC_UI_H
#define INC_UI_H

//****************************************************************************
// Include(s)
//****************************************************************************	
	
#include "main.h"
	
//****************************************************************************
// Shared variable(s)
//****************************************************************************	
	
extern uint8 minm_rgb_color;
	
//****************************************************************************
// Public Function Prototype(s):
//****************************************************************************

void i2c_init_minm(uint8 color);
void i2c_write_minm_rgb(uint8 cmd, uint8 r, uint8 g, uint8 b);
void minm_byte_to_rgb(uint8 byte, uint8 *r, uint8 *g, uint8 *b);
uint8 update_minm_rgb(void);
void minm_test_code(void);
void alive_led(void);
void power_on(void);
void set_led_rgb(unsigned char r, unsigned char g, unsigned char b);
void rgb_led_ui(uint8_t err_l0, uint8_t err_l1, uint8_t err_l2, uint8_t new_comm);

//****************************************************************************
// Definition(s):
//****************************************************************************

#define ALIVE_HALF_T				125		//ms	

//I2C - MinM
#define MINM_BUF_SIZE				5
#define I2C_SLAVE_ADDR_MINM			0x09
#define SET_RGB						'n' 
#define MINM_STOP_SCRIPT			0x6F
#define MINM_OFF					0
#define MINM_RED					1
#define MINM_GREEN					2
#define MINM_BLUE					3
#define MINM_WHITE					4

/*
 RGB LED:
========
Green: everything's good
Yellow: software error, close to a voltage or temperature limit
Blue: didn't receive commands in the last 'comm_timeout' ms
Red: error
Flashing red: major error
*/

//Timings in ms:
#define UI_COMM_TIMEOUT			2000
#define UI_L0_TIMEOUT			1000
#define UI_L1_TIMEOUT			1000
#define UI_RED_FLASH_ON			100
#define UI_RED_FLASH_PERIOD		200
		
#endif	//INC_UI_H
	