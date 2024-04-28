#include "main.h"
//extern uint8_t MOTOR1,MOTOR2,MOTOR3,MOTOR4;
//extern uint8_t Servo1,Servo2;

int main(void)
{
	delay_init();
	LED_Init();
//	HardwareGPIO_Init();
	uart_init(115200);
  TIM2_PWM_Init(19999, 71); 
	TIM4_PWM_Init(19999, 71); //舵机初始化函数
	
//	u16 PWM=1750;
//	u8  Direction=1;
  while(1)
	{ 
//		SERVO_Control4(50);
//		delay_ms(1000);
//		SERVO_Control4(180);
//		delay_ms(1000);
		if(
			SERVO3_Catch();
	}
}
