#include "GPIO.h"

//void HardwareGPIO_Init()
//{
//	GPIO_InitTypeDef GPIOB_InitStructure;
//	GPIO_InitTypeDef GPIOC_InitStructure;
//	GPIO_InitTypeDef GPIOD_InitStructure;
//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); 
//	
//	GPIOB_InitStructure.GPIO_Pin = MOTOR3_AIN_1_Pin|MOTOR3_AIN_2_Pin|MOTOR4_BIN_1_Pin|MOTOR4_BIN_2_Pin|TRANS_Pin;
//	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB,&GPIOB_InitStructure);
//	
//	GPIOC_InitStructure.GPIO_Pin = MOTOR1_AIN_1_Pin|MOTOR1_AIN_2_Pin|MOTOR2_BIN_1_Pin|PLANT_DIR_Pin|PLANT_EN_Pin;
//	GPIOC_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIOC_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOC,&GPIOC_InitStructure);
//	
//	GPIOD_InitStructure.GPIO_Pin = MOTOR2_BIN_2_Pin;
//	GPIOD_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIOD_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOD,&GPIOD_InitStructure);
//}
