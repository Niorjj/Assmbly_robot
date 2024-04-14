#include "USART.h"

void USART1_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
	  NVIC_InitTypeDef NVIC_InitStructure; 

    // �򿪴���GPIO��ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    // ��USART Tx��GPIO����Ϊ���츴��ģʽ
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // ��USART Rx��GPIO����Ϊ��������ģʽ
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
		
		NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn; //���ڴ���1�ж�
	  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE; //�ж�ʹ��
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1; //��ռ���ȼ�Ϊ1����ֵԽС���ȼ�Խ�ߣ�0�����ȼ����
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority=1; //��Ӧ���ȼ�Ϊ1����ֵԽС���ȼ�Խ�ߣ�0�����ȼ����
	  NVIC_Init(&NVIC_InitStructure); ////����NVIC_InitStrue�Ĳ�����ʼ��VIC�Ĵ��������ô���1�ж����ȼ�
}

void USART1_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
    /* ����һ���ֽ����ݵ�USART */
    USART_SendData(pUSARTx,ch);

    /* �ȴ��������ݼĴ���Ϊ�� */
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

void USART1_SendString( USART_TypeDef * pUSARTx, char *str)
{
    unsigned int k=0;
    do {
        Usart_SendByte( pUSARTx, *(str + k) );
        k++;
    } while (*(str + k)!='\0');

    /* �ȴ�������� */
    while (USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET) {
    }
}

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
