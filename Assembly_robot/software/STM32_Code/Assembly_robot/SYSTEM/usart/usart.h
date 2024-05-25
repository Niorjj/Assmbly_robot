#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#include "main.h" 
	  	    
#define PACKET_LENGTH 10
extern uint8_t j1; //��۶��
extern uint8_t j2; //С�۶��
extern uint8_t j3; //�ײ���ת���
extern uint8_t j4_state; //��ȡ״̬
extern uint8_t j5; //��ȡ��ת���
extern uint8_t j6; //Բ��״̬
extern uint8_t j7_state; //���ʹ���ͣ״̬

void USART1_Init(uint32_t bound);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);
void processPacket(uint8_t *data, uint8_t length);


#endif


