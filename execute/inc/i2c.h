//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@media.mit.edu
// 05/2016
//****************************************************************************
// i2c: I2C functions
//****************************************************************************
	
#ifndef INC_I2C_H
#define INC_I2C_H

//****************************************************************************
// Include(s)
//****************************************************************************		
	
#include "main.h"
	
//****************************************************************************
// Shared variable(s)
//****************************************************************************

extern uint8 i2c_last_request;
extern volatile uint8 i2c_0_r_buf[24];
	
//****************************************************************************
// Public Function Prototype(s):
//****************************************************************************	

void i2c_0_fsm(void);
void init_i2c_0(void);
void init_i2c_1(void);
int i2c0_read(uint8 slave_addr, uint8 reg_addr, uint8 *pdata, uint16 length);
uint8 I2C_0_MasterWriteByteTimeOut(uint8 theByte, uint32 timeout);
void assign_i2c_data(uint8 *newdata);

//****************************************************************************
// Definition(s):
//****************************************************************************	

//ISR reading of I2C0 sensors (IMU, Strain Gauge, AS5048B, etc.):									
#define I2C_RQ_GYRO				1	
#define I2C_RQ_ACCEL			2
#define I2C_RQ_AS5048B			3
#define I2C_RQ_EXT_STRAIN		4
#define I2C_RQ_BATT_BOARD		5

//****************************************************************************
// Structure(s)
//****************************************************************************	

	
#endif	//INC_I2C_H
	