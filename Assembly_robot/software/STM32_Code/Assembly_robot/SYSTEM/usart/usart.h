#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#include "main.h" 
	  	
typedef struct Data
{
	uint8_t data_head1;
	uint8_t data_head2;
	uint8_t data_j1;
	uint8_t data_j2;
	uint8_t data_j3;
	uint8_t data_j4;
	uint8_t data_j5;
	uint8_t data_j6;
	uint8_t data_j7;
	uint8_t data_j8_state;
	uint8_t data_tail;
}data;	
extern uint8_t RX_Flag;      

void USART1_Init(uint32_t bound);
void Send_Byte(uint8_t Data);
void Send_String(uint8_t *Data);
void Send_Buff(uint8_t *buf,uint16_t len);


#endif


