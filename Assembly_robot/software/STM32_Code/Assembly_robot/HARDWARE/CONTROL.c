#include "CONTROL.h"

//void MOTOR_Control1(uint16_t Angle)
//{
//	if(Angle >= 0)
//	{
//		uint16_t PWM = ;
//		TIM_SetCompare1(TIM3,PWM);
//	}else{
//		uint16_t PWM = ;
//		TIM_SetCompare1(TIM3,PWM);
//	}
//}

void MOTOR_Control2(uint16_t Angle)
{

}

//void set_steering_gear_angle(uint16_t Angle)
//{
//  Angle = (0.5 + Angle / 180.0 * (2.5 - 0.5)) / 20.0 * PWM_PERIOD_COUNT;    // 计算角度对应的占空比

//  set_steering_gear_dutyfactor(Angle);    // 设置占空比
//}
void SERVO_Control1(uint16_t Angle)
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare1(TIM2,PWM);
}

void SERVO_Control2(uint16_t Angle)
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare2(TIM2,PWM);
}

void SERVO_Control3(uint16_t Angle)
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare3(TIM2,PWM);
}

void SERVO_Control4(uint16_t Angle)
{
	uint16_t PWM = (Angle / 180 * 2000 + 500);
	TIM_SetCompare4(TIM2,PWM);
}

void PLANT_Control(uint16_t Angle)
{
	if(Angle == 0)
	{
		
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

void SERVO3_Catch(void)
{
		SERVO_Control3(50);
		delay_ms(1000);
		SERVO_Control3(180);
		delay_ms(1000);
}
