#include "usart.h"

void USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue; //����һ�����ų�ʼ���Ľṹ��
	USART_InitTypeDef USART_InitStrue; //����һ�����ڳ�ʼ���Ľṹ��
	NVIC_InitTypeDef NVIC_InitStrue; //����һ���ж����ȼ���ʼ���Ľṹ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); //GPIOAʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); //����1ʱ��ʹ��
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP; //A9������Ϊ����1�����������ţ����츴�����
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9; //����9
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_50MHz; //��Ϊ���ڷ�����������ʱ���ٶȿ���Ϊ����
  GPIO_Init(GPIOA,&GPIO_InitStrue); //�����������úõ�GPIO_InitStructure�������г�ʼ��
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING; //A10������Ϊ����1�����������ţ�������������������
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10; //����10
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz; //��Ϊ���ڽ�����������ʱ���ٶȿ���Ϊ����
  GPIO_Init(GPIOA,&GPIO_InitStrue); //�����������úõ�GPIO_InitStructure�������г�ʼ��
	
	USART_InitStrue.USART_BaudRate=115200; //���崮�ڲ�����Ϊ115200bit/s
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //��Ӳ������������
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx; //���ͽ��ռ���ģʽ
	USART_InitStrue.USART_Parity=USART_Parity_No; //����żУ��λ
	USART_InitStrue.USART_StopBits=USART_StopBits_1; //һ��ֹͣλ
	USART_InitStrue.USART_WordLength=USART_WordLength_8b; //�ֳ�Ϊ8λ���ݸ�ʽ
	USART_Init(USART1,&USART_InitStrue);//������������USART_InitStrue������ʼ������1
	
	USART_Cmd(USART1,ENABLE); //ʹ�ܴ���1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); //ʹ�ܽ����ж�void USART1_IRQHandler(void)
	
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn; //���ڴ���1�ж�
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE; //�ж�ʹ��
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1; //��ռ���ȼ�Ϊ1����ֵԽС���ȼ�Խ�ߣ�0�����ȼ����
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1; //��Ӧ���ȼ�Ϊ1����ֵԽС���ȼ�Խ�ߣ�0�����ȼ����
	NVIC_Init(&NVIC_InitStrue); ////����NVIC_InitStrue�Ĳ�����ʼ��VIC�Ĵ��������ô���1�ж����ȼ�
}


//�����жϺ���
void USART1_IRQHandler(void)
{
	  u8 Res; //����һ��ֻ�ܶ�ȡ1���ַ�
		if(USART_GetITStatus(USART1, USART_IT_RXNE)) //��ȡ����1����״̬��־λ
		{
		 Res =USART_ReceiveData(USART1);	//��ȡ���յ�������
		 USART_SendData(USART1, Res);  //�����յ�������ԭ������
		 while(USART_GetFlagStatus(USART1, USART_FLAG_TC)!=SET); //�ȴ����ͽ���
	   //USART1->DR=USART_RX_BUF[t]; //�Ĵ����汾���ڷ������ݷ��������ݼĴ��� USART_DR���Դ��Ҫ���͵�����
		 //while((USART1->SR&0X40)==0); //USART_SR �Ĵ�����TCλ��0ʱ���ݷ��ͽ���
    } 
}

void USART1_Send_Byte(unsigned char byte)
{
	USART_SendData(USART1,byte);
	while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
}

void UART1_Send_Str(unsigned char *s)//�����ַ��� ����   Ӧ��ָ�� ����
{
   unsigned char i=0;  //����һ���ֲ�����  ���� �����ַ��� ++����

   while(s[i]!='\0')  // ÿ���ַ�����β ������  \0 ��β��
   {
       USART_SendData(USART1,s[i]);        //ͨ���⺯��  ��������
       while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);  
          i++;                 
   }
}
