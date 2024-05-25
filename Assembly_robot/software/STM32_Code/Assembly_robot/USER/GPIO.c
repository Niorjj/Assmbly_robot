#include "GPIO.h"

void Motor_Init(void)
{
	GPIO_InitTypeDef GPIO_Motor1_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	
	GPIO_Motor1_InitStructure.GPIO_Pin = MOTOR_PUL|MOTOR_DIR|MOTOR_EN;
	GPIO_Motor1_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor1_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR_Port,&GPIO_Motor1_InitStructure);

	GPIO_SetBits(MOTOR_Port,MOTOR_EN);
}

void Plant_Trans_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  
	
	GPIO_InitStructure.GPIO_Pin = PLANT_PUL_Pin|PLANT_DIR_Pin|PLANT_EN_Pin|TRANS_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_SetBits(GPIOB,PLANT_EN_Pin);
	GPIO_SetBits(GPIOB,TRANS_Pin);
}

