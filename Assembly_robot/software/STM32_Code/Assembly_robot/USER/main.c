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
		//夹取动作
		TIM_SetCompare3(TIM2,2000); //夹取舵机
		TIM_SetCompare3(TIM2,1500); 
		delay_ms(1000);
		TIM_SetCompare2(TIM2,2100); //底部旋转舵机 
		TIM_SetCompare4(TIM1,1600); //小臂舵机
		TIM_SetCompare1(TIM1,500); //大臂舵机
		TIM_SetCompare4(TIM2,1000); //旋转舵机
//		TIM_SetCompare3(TIM2,2000); 
	}
}
