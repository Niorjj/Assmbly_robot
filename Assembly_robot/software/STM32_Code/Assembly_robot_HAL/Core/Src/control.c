#include "control.h"
#include "tim.h"

void MOTOR1_Angle(uint16_t Angle)
{
	if(Angle > 0)
	{
		
	}else if(Angle < 0)
	{
		
	}
}
void MOTOR2_Angle(uint16_t Angle)
{
	if(Angle > 0)
	{
		
	}else if(Angle < 0)
	{
		
	}
}
void MOTOR3_Angle(uint16_t Angle)
{
	if(Angle > 0)
	{
		
	}else if(Angle < 0)
	{
		
	}
}
void MOTOR4_Angle(uint16_t Angle)
{
	if(Angle > 0)
	{
		
	}else if(Angle < 0)
	{
		
	}	
}
void TRANSE_Control(uint8_t State)
{
	if(State ==1 )
	{
		HAL_GPIO_WritePin(TRANS_Port,TRANS_Pin,GPIO_PIN_SET);
	}else if(State == 0)
	{
		HAL_GPIO_WritePin(TRANS_Port,TRANS_Pin,GPIO_PIN_RESET);
	}
}
void PLANT_Angle(uint16_t Angle)
{
	if(Angle == 0)
	{
		
	}else if(Angle == 45)
	{
		
	}else if(Angle == 90)
	{
		
	}else if(Angle == 135)
	{
		
	}else if(Angle == 180)
	{
		
	}else if(Angle == 225)
	{
		
	}else if(Angle == 270)
	{
		
	}else if(Angle == 315)
	{
		
	}
}
/* USER CODE BEGIN 4 */
void Servo1_Angle(uint16_t angle)
{
	
}
void Servo2_Angle(uint16_t angle)
{
    // 将角度转换为对应的PWM脉宽值
    uint32_t pulse_width = 1000 + (angle * (2000 - 1000)) / 180;

    // 设置TIM2的PWM输出通道1的脉宽
    TIM_OC_InitTypeDef sConfigOC;
    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = pulse_width;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_ENABLE;
    HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}
/* USER CODE END 4 */

