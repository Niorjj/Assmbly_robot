#include "CONTROL.h"

void MOTOR_Control(uint8_t Angle)
{
	uint16_t n =(uint16_t)Angle / MOTOR_STEP_ANGLE;
	GPIO_SetBits(MOTOR_Port,MOTOR_EN);
	if(Angle > 0)
	{
		GPIO_SetBits(MOTOR_Port,MOTOR_DIR);
	}else{
		GPIO_ResetBits(MOTOR_Port,MOTOR_DIR);
	}
	for(uint16_t i =0;i<n;i++)
	{
		GPIO_SetBits(MOTOR_Port,MOTOR_PUL);
		delay_ms(1);
		GPIO_ResetBits(MOTOR_Port,MOTOR_PUL);
		delay_ms(1);
	}
}

void SERVO_Control1(uint16_t Angle) //大臂舵机
{
	uint16_t PWM = Angle;
	TIM_SetCompare1(TIM1,PWM);
}

void SERVO_Control2(uint16_t Angle) //小臂舵机
{
	uint16_t PWM = Angle;
	TIM_SetCompare4(TIM1,PWM);
}

void SERVO_Control3(uint16_t Angle) //底部旋转舵机
{
	uint16_t PWM = (Angle / 90 * 650 + 1450);
	TIM_SetCompare2(TIM2,PWM);
}

void SERVO_Control4(uint16_t state) //机械爪夹取舵机
{
	uint16_t PWM;
	if(state == 0) //闭合
		PWM = 2000;
	if(state == 1) //打开
		PWM = 1500;
	TIM_SetCompare3(TIM2,PWM);
}

void SERVO_Control5(uint16_t Angle) //机械爪旋转舵机
{
	uint16_t PWM = (Angle / 45 * 500 + 1000);
	TIM_SetCompare4(TIM2,PWM);
}

void PLANT_Control(uint8_t Angle) //圆盘角度控制
{
	if(Angle > 0)
	{
		uint8_t num =0;
		num = Angle/MOTOR_STEP_ANGLE;
		GPIO_SetBits(GPIOA,PLANT_DIR_Pin);
		for(int i=0;i < num;i++)
		{
			GPIO_SetBits(GPIOC,PLANT_PUL_Pin);
			delay_ms(1);
			GPIO_ResetBits(GPIOC,PLANT_PUL_Pin);
			delay_ms(1);
		}
	}else{
		GPIO_ResetBits(GPIOA,PLANT_DIR_Pin);
	}
}

void TRANSE_Control(uint8_t State)
{
	if(State == 1)
	{
		GPIO_SetBits(GPIOC,TRANS_Pin);
	}
	else if(State == 0)
	{
		GPIO_ResetBits(GPIOC,TRANS_Pin);
	}
}

