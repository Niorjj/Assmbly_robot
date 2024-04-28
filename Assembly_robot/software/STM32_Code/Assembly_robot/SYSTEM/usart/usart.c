#include "sys.h"
#include "usart.h"	  
#include "string.h"

//////////////////////////////////////////////////////////////////////////////////// 	 
////如果使用ucos,则包括下面的头文件即可.
//#if SYSTEM_SUPPORT_OS
//#include "includes.h"					//ucos 使用	  
//#endif  
// 
////////////////////////////////////////////////////////////////////
////加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
//#if 1
//#pragma import(__use_no_semihosting)             
////标准库需要的支持函数                 
//struct __FILE 
//{ 
//	int handle; 

//}; 

//FILE __stdout;       
////定义_sys_exit()以避免使用半主机模式    
//void _sys_exit(int x) 
//{ 
//	x = x; 
//} 
////重定义fputc函数 
//int fputc(int ch, FILE *f)
//{      
//	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
//    USART1->DR = (u8) ch;      
//	return ch;
//}
//#endif 

// 
// 
//#if EN_USART1_RX   //如果使能了接收
////串口1中断服务程序
////注意,读取USARTx->SR能避免莫名其妙的错误   	
//u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
////接收状态
////bit15，	接收完成标志
////bit14，	接收到0x0d
////bit13~0，	接收到的有效字节数目

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
	J1 = RX_Buffer[2]; //大臂舵机
	J2 = RX_Buffer[3]; //小臂舵机
	J3 = RX_Buffer[4]; //夹取舵机
	J4 = RX_Buffer[5]; //旋转舵机
	J5 = RX_Buffer[6]; //底部旋转电机
	J6 = RX_Buffer[7]; //底部平移电机 
	J7 = RX_Buffer[8]; //圆盘旋转角度
	J8_State = RX_Buffer[9]; //传送带启动停止状态
}
//#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
//	OSIntEnter();    
//#endif
//	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  
//		{
//		Res =USART_ReceiveData(USART1);	//读取接收到的数据
		
//		if((USART_RX_STA&0x8000)==0)//接收未完成
//			{
//			if(USART_RX_STA&0x4000)//接收到了0x0d
//				{
//				if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
//				else USART_RX_STA|=0x8000;	//接收完成了 
//				}
//			else //还没收到0X0D
//				{	
//				if(Res==0x0d)USART_RX_STA|=0x4000;
//				else
//					{
//					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
//					USART_RX_STA++;
//					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//接收数据错误,重新开始接收	  
//					}		 
//				}
//			}   		 
//     } 
//#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
//	OSIntExit();  											 
//#endif
// 
//#endif	

