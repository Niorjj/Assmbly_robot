#include "main.h"

uint16_t j1 = 0;
uint16_t j2 = 0;
uint16_t j3 = 0;
uint16_t j4 = 0;
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
		SERVO_Control4(0);
		delay_ms(1000);
		SERVO_Control5(0);
//		SERVO_Control4(1);
		delay_ms(1000);
	}
}
