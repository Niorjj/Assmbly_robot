#include "USART.h"

void USART1_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
	  NVIC_InitTypeDef NVIC_InitStructure; 

    // 打开串口GPIO的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    // 将USART Tx的GPIO配置为推挽复用模式
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 将USART Rx的GPIO配置为浮空输入模式
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No ;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
   
    USART_Cmd(USART1, ENABLE);
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
		
		NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn; //属于串口1中断
	  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE; //中断使能
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1; //抢占优先级为1级，值越小优先级越高，0级优先级最高
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority=1; //响应优先级为1级，值越小优先级越高，0级优先级最高
	  NVIC_Init(&NVIC_InitStructure); ////根据NVIC_InitStrue的参数初始化VIC寄存器，设置串口1中断优先级
}

void USART1_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
    /* 发送一个字节数据到USART */
    USART_SendData(pUSARTx,ch);

    /* 等待发送数据寄存器为空 */
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

void USART1_SendString( USART_TypeDef * pUSARTx, char *str)
{
    unsigned int k=0;
    do {
        Usart_SendByte( pUSARTx, *(str + k) );
        k++;
    } while (*(str + k)!='\0');

    /* 等待发送完成 */
    while (USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET) {
    }
}

void USART1_IRQHandler(void)
{
	  u8 Res; //串口一次只能读取1个字符
		if(USART_GetITStatus(USART1, USART_IT_RXNE)) //获取串口1接收状态标志位
		{
		 Res =USART_ReceiveData(USART1);	//读取接收到的数据
		 USART_SendData(USART1, Res);  //将接收到的数据原样发送
		 while(USART_GetFlagStatus(USART1, USART_FLAG_TC)!=SET); //等待发送结束
	   //USART1->DR=USART_RX_BUF[t]; //寄存器版本串口发送数据方法，数据寄存器 USART_DR可以存放要发送的数据
		 //while((USART1->SR&0X40)==0); //USART_SR 寄存器的TC位置0时数据发送结束
    } 
}
