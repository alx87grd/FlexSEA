//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@media.mit.edu
// 05/2015
//****************************************************************************
// fm_uarts: Deals with the 3 USARTs
//****************************************************************************
// Licensing: Please refer to 'software_license.txt'
//****************************************************************************

#ifndef INC_UARTS_H
#define INC_UARTS_H

//****************************************************************************
// Include(s)
//****************************************************************************

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

//****************************************************************************
// Shared Variable(s)
//****************************************************************************

extern USART_HandleTypeDef husart1;		//RS-485 #1
extern USART_HandleTypeDef husart6;		//RS-485 #2
extern USART_HandleTypeDef husart3;		//Expansion port
extern DMA_HandleTypeDef hdma2_str2_ch4;	//DMA for RS-485 #1 RX
extern DMA_HandleTypeDef hdma2_str7_ch4;	//DMA for RS-485 #1 TX
extern DMA_HandleTypeDef hdma2_str1_ch5;	//DMA for RS-485 #2 RX
extern DMA_HandleTypeDef hdma2_str6_ch5;	//DMA for RS-485 #2 TX

//****************************************************************************
// Public Function Prototype(s):
//****************************************************************************

//General:
void init_rs485_outputs(void);
void rs485_set_mode(uint32_t port, uint8_t rx_tx);

//RS-485 #1:
void init_usart1(uint32_t baudrate);
void putc_usart1(char c);
void puts_rs485_1(uint8_t *str, uint16_t length);
uint8_t reception_rs485_1_blocking(void);
void DMA2_Str2_CompleteTransfer_Callback(DMA_HandleTypeDef *hdma);
void DMA2_Str7_CompleteTransfer_Callback(DMA_HandleTypeDef *hdma);
void rs485_1_xmit_dma_rx_test(void);

//RS-485 #2:
void init_usart6(uint32_t baudrate);
void putc_usart6(char c);
void puts_rs485_2(uint8_t *str, uint16_t length);
uint8_t reception_rs485_2_blocking(void);
void DMA2_Str1_CompleteTransfer_Callback(DMA_HandleTypeDef *hdma);
void DMA2_Str6_CompleteTransfer_Callback(DMA_HandleTypeDef *hdma);
void rs485_2_xmit_dma_rx_test(void);

//Other USART:
void init_usart3(uint32_t baudrate);

//****************************************************************************
// Definition(s):
//****************************************************************************

#define UART_TIMEOUT		5000	//ms?

//Baud = fck/(8*(2-OVER8)*USARTDIV) and OVER8 = 1 so Baud = fck/(8*USARTDIV)
//USARTDIV = fck / (8*Baud)
//1Mbits/s: 84MHz / (8*1e6) = 10.5 => 1010 0 100 => 164
#define USART1_6_1MBAUD		164
#define USART1_6_2MBAUD		82
#define USART1_6_3MBAUD		49	//It's 3.333
#define USART1_6_4MBAUD		37

//USART1 (RS-485 #1):
//===================
//RE1:	 	PF12
//DE1: 		PF11

//USART6 (RS-485 #2):
//===================
//RE4:		PE11
//DE4:		PE10

//Common define
#define RS485_STANDBY			0x00
#define RS485_RX			0x01
#define RS485_TX			0x02
#define RS485_RX_TX			0x03

//Interrupt priorities (lower number = higher priority)
#define UART1_IRQ_CHANNEL		6
#define UART1_IRQ_SUBCHANNEL		0

#define UART6_IRQ_CHANNEL		UART1_IRQ_CHANNEL
#define UART6_IRQ_SUBCHANNEL		1

#define UART3_IRQ_CHANNEL		8
#define UART3_IRQ_SUBCHANNEL		0

#define DMA_STR2_IRQ_CHANNEL		5	//UART1 RX
#define DMA_STR2_IRQ_SUBCHANNEL		0

#define DMA_STR1_IRQ_CHANNEL		5	//UART6 RX
#define DMA_STR1_IRQ_SUBCHANNEL		1

#define DMA_STR7_IRQ_CHANNEL		7	//UART1 TX
#define DMA_STR7_IRQ_SUBCHANNEL		0

#define DMA_STR6_IRQ_CHANNEL		7	//UART6 TX
#define DMA_STR6_IRQ_SUBCHANNEL		1

#endif // INC_UARTS_H

