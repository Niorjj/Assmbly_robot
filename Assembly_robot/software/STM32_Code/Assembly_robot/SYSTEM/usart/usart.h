#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#include "main.h" 
	  	    
#define PACKET_LENGTH 10
extern uint8_t j1; //大臂舵机
extern uint8_t j2; //小臂舵机
extern uint8_t j3; //底部旋转舵机
extern uint8_t j4_state; //夹取状态
extern uint8_t j5; //夹取旋转舵机
extern uint8_t j6; //圆盘状态
extern uint8_t j7_state; //传送带启停状态

void USART1_Init(uint32_t bound);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);
void processPacket(uint8_t *data, uint8_t length);


#endif


