#include "main.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	Motor_Init();
	USART1_Init(115200);
	TIM1_PWM_Init(19999, 71); 
  TIM2_PWM_Init(19999, 71); 
  while(1)
	{ 
		//��ȡ����
		TIM_SetCompare3(TIM2,2000); //��ȡ���
		TIM_SetCompare3(TIM2,1500); 
		delay_ms(1000);
		TIM_SetCompare2(TIM2,2100); //�ײ���ת��� 
		TIM_SetCompare4(TIM1,1600); //С�۶��
		TIM_SetCompare1(TIM1,500); //��۶��
		TIM_SetCompare4(TIM2,1000); //��ת���
//		TIM_SetCompare3(TIM2,2000); 
	}
}
