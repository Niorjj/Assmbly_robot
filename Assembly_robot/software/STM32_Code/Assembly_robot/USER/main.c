#include "main.h"
extern uint16_t J1,J2,J3,J4,J5,J6,J7;
extern uint8_t J8_State;

int main(void)
{
	delay_init();
	LED_Init();
	Motor_Init();
	uart_init(115200);
	TIM1_PWM_Init(19999, 71); 
  TIM2_PWM_Init(19999, 71); 
	TIM8_PWM_Init(19999, 71); 
	
  while(1)
	{ 
		SERVO_Control1(J1);
		SERVO_Control2(J2);
		SERVO_Control3(J3);
		SERVO_Control4(J4);
		MOTOR_Control1(J5);
		MOTOR_Control2(J6);
		PLANT_Control(J7);
		TRANSE_Control(J8_State);
	}
}
