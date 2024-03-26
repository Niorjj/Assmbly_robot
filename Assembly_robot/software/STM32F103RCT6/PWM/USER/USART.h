#ifndef __USART_H 
#define __USART_H 

#include "sys.h"
#include "stm32f10x_tim.h"

void USART1_Config(void);
void USART1_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void USART1_SendString( USART_TypeDef * pUSARTx, char *str);

#endif 