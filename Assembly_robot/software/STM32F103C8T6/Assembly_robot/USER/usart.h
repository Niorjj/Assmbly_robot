#ifndef __USART_H
#define __USART_H	
#include "sys.h"

#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"

void USART1_Init(int Baud_rate);
void USART1_IRQHandler(void);
void USART1_Send_Byte(unsigned char byte);
void UART1_Send_Str(unsigned char *s);
	
#endif
