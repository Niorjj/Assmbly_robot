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

void SERVO_Control1(uint8_t Angle) //��۶��
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare1(TIM1,PWM);
}

void SERVO_Control2(uint8_t Angle) //С�۶��
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare4(TIM1,PWM);
}

void SERVO_Control3(uint8_t Angle) //�ײ���ת���
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare2(TIM2,PWM);
}

void SERVO_Control4(uint8_t Angle) //��еצ��ȡ���
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare3(TIM2,PWM);
}

void SERVO_Control5(uint8_t Angle) //��еצ��ת���
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare4(TIM2,PWM);
}

void PLANT_Control(uint8_t Angle) //Բ�̽Ƕȿ���
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

