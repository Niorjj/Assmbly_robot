#include "led.h" 
#include "usart.h"
#include "delay.h"

int main(void)
{	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����ж����ȼ�����
	USART1_Init(); //���ô���1��ʼ������
	while(1)
	{
		USART1_Send_Byte("1");
	  //�������������������û����Զ���
	}
}

