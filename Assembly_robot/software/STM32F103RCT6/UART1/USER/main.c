#include "led.h" 
#include "usart.h"
#include "delay.h"

int main(void)
{	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断优先级分组
	USART1_Init(); //调用串口1初始化函数
	while(1)
	{
		USART1_Send_Byte("1");
	  //本次例程无主函数，用户可自定义
	}
}

