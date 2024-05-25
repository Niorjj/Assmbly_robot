#include "main.h"

uint8_t j1 = 0;
uint8_t j2 = 0;
uint8_t j3 = 90;
uint8_t j4_state = 0;
uint8_t j5 = 0; //夹取旋转舵机
uint8_t j6 = 0; //圆盘状态
uint8_t j7_state = 0;//停止
uint8_t j8_state = 0;//步进电机起始
int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	Motor_Init();
	Plant_Trans_Init();
	USART1_Init(115200);
	TIM1_PWM_Init(19999, 71); 
  TIM2_PWM_Init(19999, 71); 
  while(1)
	{ 
//		if(j7_state == 0)
//			TRANSE_Control(0);
//		else if(j7_state == 1)
//			TRANSE_Control(1);
		SERVO_Control1(1500);
//		MOTOR_Control(100);
		SERVO_Control2(1500);
		SERVO_Control3(0);
		SERVO_Control4(1);
		delay_ms(1000);
		SERVO_Control4(0);	
		delay_ms(1000);
		SERVO_Control5(0);
		delay_ms(1000);
	}
}
