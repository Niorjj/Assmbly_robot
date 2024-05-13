#include "GPIO.h"

void Motor_Init(void)
{
	GPIO_InitTypeDef GPIO_Motor1_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	
	GPIO_Motor1_InitStructure.GPIO_Pin = MOTOR_PUL|MOTOR_DIR|MOTOR_EN;
	GPIO_Motor1_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor1_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_Port,&GPIO_Motor1_InitStructure);

	GPIO_SetBits(MOTOR_Port,MOTOR_EN);
}

