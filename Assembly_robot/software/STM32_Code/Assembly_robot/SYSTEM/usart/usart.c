#include "sys.h"
#include "usart.h"	  
#include "string.h"


void Send_Byte(uint8_t Data)
{
	USART_GetFlagStatus(USART1,USART_FLAG_TC);
	USART_SendData(USART1,Data);
}

void Send_String(uint8_t *Data)
{
	while(*Data)
		Send_Byte(*Data ++);
}

void Send_Buff(uint8_t *buf,uint16_t len)
{
	uint16_t i;
	for(i =0;i<len;i++)
	{
		Send_Byte(buf[i]);
	}
}

void USART1_Init(uint32_t bound)
{
  GPIO_InitTypeDef GPIO_InitStrue; 
	USART_InitTypeDef USART_InitStrue; 
	NVIC_InitTypeDef NVIC_InitStrue; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP; 
	GPIO_InitStrue.GPIO_Pin=USART1_TX_Pin; 
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
  GPIO_Init(GPIOA,&GPIO_InitStrue); 
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStrue.GPIO_Pin=USART1_RX_Pin; 
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
  GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	USART_InitStrue.USART_BaudRate=bound; 
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None; 
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx; 
	USART_InitStrue.USART_Parity=USART_Parity_No; 
	USART_InitStrue.USART_StopBits=USART_StopBits_1; 
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStrue);
	
	USART_Cmd(USART1,ENABLE); 
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); 
	
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn; 
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE; 
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1; 
	NVIC_Init(&NVIC_InitStrue); 
}

uint8_t RX_Buffer[15];
uint8_t RX_Index =0;
uint8_t RX_Flag =0;
void USART1_IRQHandler(void)
{
//		{
//        u8 tem = 0;
//    if( USART_GetITStatus( USART2, USART_IT_RXNE ) != RESET )   //接收中断  接收到一个字节产生一次中断
//    {
//        tem = USART_ReceiveData( USART2 );	 //读取数据，可以自动将中断标志位RXNE清零
//        RX_Buffer[RX_Index++] = tem;	 //存储接收到的数据
//    }
//    if( USART_GetITStatus( USART2, USART_IT_IDLE ) != RESET )//空闲中断 接收到一帧数据 产生一次中断
//    {
//        tem = USART2->SR;	 //读取SR寄存器
//        tem = USART2->DR;    //读取DR寄存器 (先读USART_SR，然后读USART_DR可以清除空闲中断标志位IDLE)
//        copy_data(RX_Buffer,RX_Index);	//备份数据
//        RX_Flag = 1;						//接收完成标志位置位
//        RX_Index = 0;	                    //接收数据长度清零
//    }
//		}
//    USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}


