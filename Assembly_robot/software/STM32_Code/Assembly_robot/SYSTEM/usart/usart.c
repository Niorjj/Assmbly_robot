#include "sys.h"
#include "usart.h"	  
#include "string.h"

//////////////////////////////////////////////////////////////////////////////////// 	 
////���ʹ��ucos,����������ͷ�ļ�����.
//#if SYSTEM_SUPPORT_OS
//#include "includes.h"					//ucos ʹ��	  
//#endif  
// 
////////////////////////////////////////////////////////////////////
////�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
//#if 1
//#pragma import(__use_no_semihosting)             
////��׼����Ҫ��֧�ֺ���                 
//struct __FILE 
//{ 
//	int handle; 

//}; 

//FILE __stdout;       
////����_sys_exit()�Ա���ʹ�ð�����ģʽ    
//void _sys_exit(int x) 
//{ 
//	x = x; 
//} 
////�ض���fputc���� 
//int fputc(int ch, FILE *f)
//{      
//	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
//    USART1->DR = (u8) ch;      
//	return ch;
//}
//#endif 

// 
// 
//#if EN_USART1_RX   //���ʹ���˽���
////����1�жϷ������
////ע��,��ȡUSARTx->SR�ܱ���Ī������Ĵ���   	
//u8 USART_RX_BUF[USART_REC_LEN];     //���ջ���,���USART_REC_LEN���ֽ�.
////����״̬
////bit15��	������ɱ�־
////bit14��	���յ�0x0d
////bit13~0��	���յ�����Ч�ֽ���Ŀ

uint16_t RX_State=0;  
uint16_t RX_Buffer[15]; 
uint16_t J1,J2,J3,J4,J5,J6,J7;
uint8_t J8_State;
  
void uart_init(uint32_t bound){
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

  GPIO_InitStructure.GPIO_Pin = UART4_TX_Pin;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	
  GPIO_Init(UART4_Port, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = UART4_RX_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(UART4_Port, &GPIO_InitStructure); 

  NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		
	NVIC_Init(&NVIC_InitStructure);	

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	
	USART_Init(UART4, &USART_InitStructure); 
  
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
  
	USART_Cmd(UART4, ENABLE);            

}

void UART4_Send_Byte(uint8_t Data)
{
	USART_GetFlagStatus(UART4,USART_FLAG_TC);
	USART_SendData(UART4,Data);
}

void UART4_Send_String(uint8_t *Data)
{
	while(*Data)
		UART4_Send_Byte(*Data ++);
}

void UART4_IRQHandler(void)        
{
	if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)  
	{
		for(int i=0;i<sizeof(RX_Buffer);i++)
		{
			RX_Buffer[i]=USART_ReceiveData(UART4);
			if(RX_Buffer[0] == '0xAA'&& RX_Buffer[1] == '0xBB')
			{
				
				if(RX_Buffer[sizeof(RX_Buffer)-2] == '\r'&& RX_Buffer[sizeof(RX_Buffer)-1] == '\n')
				{
					
				}
			}
		}
	}
	USART_ClearITPendingBit(UART4, USART_IT_RXNE);
}

void Data_Explain(void)
{
	J1 = RX_Buffer[2]; //��۶��
	J2 = RX_Buffer[3]; //С�۶��
	J3 = RX_Buffer[4]; //��ȡ���
	J4 = RX_Buffer[5]; //��ת���
	J5 = RX_Buffer[6]; //�ײ���ת���
	J6 = RX_Buffer[7]; //�ײ�ƽ�Ƶ�� 
	J7 = RX_Buffer[8]; //Բ����ת�Ƕ�
	J8_State = RX_Buffer[9]; //���ʹ�����ֹͣ״̬
}
//#if SYSTEM_SUPPORT_OS 		//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
//	OSIntEnter();    
//#endif
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  
//		{
//		Res =USART_ReceiveData(USART1);	//��ȡ���յ�������
		
//		if((USART_RX_STA&0x8000)==0)//����δ���
//			{
//			if(USART_RX_STA&0x4000)//���յ���0x0d
//				{
//				if(Res!=0x0a)USART_RX_STA=0;//���մ���,���¿�ʼ
//				else USART_RX_STA|=0x8000;	//��������� 
//				}
//			else //��û�յ�0X0D
//				{	
//				if(Res==0x0d)USART_RX_STA|=0x4000;
//				else
//					{
//					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
//					USART_RX_STA++;
//					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
//					}		 
//				}
//			}   		 
//     } 
//#if SYSTEM_SUPPORT_OS 	//���SYSTEM_SUPPORT_OSΪ�棬����Ҫ֧��OS.
//	OSIntExit();  											 
//#endif
// 
//#endif	
