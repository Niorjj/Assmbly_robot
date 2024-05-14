#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#include "main.h" 
	  	    
extern uint16_t j1;
extern uint16_t j2;
extern uint16_t j3;
extern uint16_t j4;

void USART1_Init(uint32_t bound);
void Send_Byte(uint8_t Data);
void Send_String(uint8_t *Data);
void Send_Buff(uint8_t *buf,uint16_t len);


#endif


