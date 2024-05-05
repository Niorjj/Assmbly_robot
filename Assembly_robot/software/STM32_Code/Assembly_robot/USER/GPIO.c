#include "GPIO.h"

void Motor_Init(void)
{
	GPIO_InitTypeDef GPIO_Motor1_InitStructure;
	GPIO_InitTypeDef GPIO_Motor2_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	
	GPIO_Motor1_InitStructure.GPIO_Pin = MOTOR1_PUL|MOTOR1_DIR|MOTOR1_EN;
	GPIO_Motor1_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor1_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR1_Port,&GPIO_Motor1_InitStructure);
	
	GPIO_Motor2_InitStructure.GPIO_Pin = MOTOR2_PUL|MOTOR2_DIR|MOTOR2_EN;
	GPIO_Motor2_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Motor2_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOTOR2_Port,&GPIO_Motor2_InitStructure);
	
	GPIO_SetBits(MOTOR1_Port,MOTOR1_EN);
	GPIO_SetBits(MOTOR2_Port,MOTOR2_EN);
}

