#ifndef __MAIN_H
#define __MAIN_H	
#include "TIMER.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "GPIO.h"
#include "CONTROL.h"

//大臂步进电机
#define MOTOR1_AIN_Port GPIOB
#define MOTOR1_AIN_1_Pin GPIO_Pin_3
#define MOTOR1_AIN_2_Pin GPIO_Pin_4
#define MOTOR2_BIN_1_Pin GPIO_Pin_5
//小臂步进电机
#define MOTOR2_BIN_2_Port GPIOC
#define MOTOR2_BIN_2_Pin GPIO_Pin_14
//底部旋转步进电机
#define MOTOR3_AIN_Port GPIOB
#define MOTOR3_AIN_1_Pin GPIO_Pin_5
#define MOTOR3_AIN_2_Pin GPIO_Pin_6
//直线模组步进电机
#define MOTOR4_BIN_Port GPIOB
#define MOTOR4_BIN_1_Pin GPIO_Pin_7
#define MOTOR4_BIN_2_Pin GPIO_Pin_4
//USART1
#define USART1_Port GPIOA
#define USART1_TX_Pin GPIO_Pin_9
#define USART1_RX_Pin GPIO_Pin_10
//USART3
#define USART3_Port GPIOB
#define USART3_TX_Pin GPIO_Pin_10
#define USART3_RX_Pin GPIO_Pin_11
//TIM2
#define TIM2_Port GPIOA 
#define TIM2_CH1_Pin GPIO_Pin_8 //大臂步进舵机
#define TIM2_CH2_Pin GPIO_Pin_11 //小臂步进舵机
#define TIM2_CH3_Pin GPIO_Pin_2 //机械爪旋转舵机
#define TIM2_CH4_Pin GPIO_Pin_3 //机械爪夹取舵机
//TIM4
#define TIM4_CH12_Port GPIOB 
#define TIM4_CH1_Pin GPIO_Pin_6//底部旋转步进电机
#define TIM4_CH2_Pin GPIO_Pin_7//直线模组步进电机
//TRANS传送带
#define TRANS_Port GPIOB //传送带启停端
#define TRANS_Pin GPIO_Pin_1
//PLANT装配圆盘
#define PLANT_Port GPIOC
#define TIM8_CH1_Pin GPIO_Pin_6
#define PLANT_DIR_Port GPIOA
#define PLANT_DIR_Pin GPIO_Pin_1 //装配盘DIR
#define PLANT_EN_Pin GPIO_Pin_15 //装配盘EN
//LED
#define LED_Port GPIOB
#define LED_Pin GPIO_Pin_13
#define LED_KEY_Pin GPIO_Pin_14
#define MOTOR_STEP_ANGLE 1.8


#endif
