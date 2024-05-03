#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 
#include "main.h" 

#define USART_REC_LEN  			200  	//�����������ֽ��� 200
#define EN_USART1_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	
//����봮���жϽ��գ��벻Ҫע�����º궨��
void uart_init(uint32_t bound);
void UART4_Send_Byte(uint8_t Data);
void UART4_Send_String(uint8_t *Data);
void Data_Explain(void);
#endif


