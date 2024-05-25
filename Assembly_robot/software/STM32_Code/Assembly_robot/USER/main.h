#ifndef __MAIN_H
#define __MAIN_H	
#include "TIMER.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "GPIO.h"
#include "CONTROL.h"

//底部旋转步进电机
#define MOTOR_Port GPIOB
#define MOTOR_PUL GPIO_Pin_3
#define MOTOR_DIR GPIO_Pin_4
#define MOTOR_EN GPIO_Pin_5
//USART4
#define USART1_Port GPIOA
#define USART1_TX_Pin GPIO_Pin_9
#define USART1_RX_Pin GPIO_Pin_10
//TIM
#define TIM1_CH1_Pin GPIO_Pin_8 //大臂舵机
#define TIM1_CH4_Pin GPIO_Pin_11 //小臂舵机
#define TIM2_CH2_Pin GPIO_Pin_1 //底部旋转舵机
#define TIM2_CH3_Pin GPIO_Pin_2 //机械爪旋转舵机
#define TIM2_CH4_Pin GPIO_Pin_3 //机械爪夹取舵机
//TRANS传送带PB14
#define TRANS_Pin GPIO_Pin_14
//PLANT装配圆盘PB15 PB10 PB11 
#define PLANT_PUL_Pin GPIO_Pin_15
#define PLANT_DIR_Pin GPIO_Pin_10//装配盘DIR
#define PLANT_EN_Pin GPIO_Pin_11 //装配盘EN
#define MOTOR_STEP_ANGLE 1.8
#define lengthpercir 0.4
#define LED_Port GPIOB
#define LED_Pin GPIO_Pin_13


#endif
