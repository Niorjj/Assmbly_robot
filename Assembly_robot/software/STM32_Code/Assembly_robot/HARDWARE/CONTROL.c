#include "CONTROL.h"

void MOTOR_Control1(uint16_t Angle)
{
	uint16_t n =(uint16_t)Angle / MOTOR_STEP_ANGLE;
	
	if(Angle > 0)
	{
		GPIO_SetBits(MOTOR1_Port,MOTOR1_DIR);
	}else{
		GPIO_ResetBits(MOTOR1_Port,MOTOR1_DIR);
	}
	for(uint16_t i =0;i<n;i++)
	{
		GPIO_SetBits(MOTOR1_Port,MOTOR1_PUL);
		delay_ms(1);
		GPIO_ResetBits(MOTOR1_Port,MOTOR1_PUL);
		delay_ms(1);
	}
}

void MOTOR_Control2(uint16_t Angle)
{
	uint16_t n =(uint16_t)Angle / MOTOR_STEP_ANGLE;
	
	if(Angle > 0)
	{
		GPIO_SetBits(MOTOR2_Port,MOTOR2_DIR);
	}else{
		GPIO_ResetBits(MOTOR2_Port,MOTOR2_DIR);
	}
	for(uint16_t i =0;i<n;i++)
	{
		GPIO_SetBits(MOTOR2_Port,MOTOR2_PUL);
		delay_ms(1);
		GPIO_ResetBits(MOTOR2_Port,MOTOR2_PUL);
		delay_ms(1);
	}
}

void SERVO_Control1(uint16_t Angle) //大臂舵机
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare1(TIM1,PWM);
}

void SERVO_Control2(uint16_t Angle) //小臂舵机
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare4(TIM1,PWM);
}

void SERVO_Control3(uint16_t Angle) //夹取舵机
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare3(TIM2,PWM);
}

void SERVO_Control4(uint16_t Angle) //旋转舵机
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare4(TIM2,PWM);
}

void PLANT_Control(uint16_t Angle) //圆盘角度控制
{
	if(Angle > 0)
	{
		GPIO_SetBits(GPIOA,PLANT_DIR_Pin);
		for(int i=0;i < Angle/MOTOR_STEP_ANGLE;i++)
		{
			
		}
	}else{
		GPIO_ResetBits(GPIOA,PLANT_DIR_Pin);
	}
}

void TRANSE_Control(uint8_t State)
{
	if(State == 1)
	{
		GPIO_SetBits(TRANS_Port,TRANS_Pin);
	}
	else if(State == 0)
	{
		GPIO_ResetBits(TRANS_Port,TRANS_Pin);
	}
}

