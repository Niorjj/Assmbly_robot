#ifndef __MAIN_H
#define __MAIN_H	
#include "TIMER.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "GPIO.h"
#include "CONTROL.h"

//底部旋转步进电机
#define MOTOR1_Port
#define MOTOR1_PUL
#define MOTOR1_DIR
#define MOTOR1_EN
//直线模组步进电机
#define MOTOR2_Port
#define MOTOR2_PUL
#define MOTOR2_DIR
#define MOTOR2_EN
//USART4
#define UART4_Port GPIOC
#define UART4_TX_Pin GPIO_Pin_10
#define UART4_RX_Pin GPIO_Pin_11
//TIM2
#define TIM1_CH1_Pin GPIO_Pin_8 //大臂步进舵机
#define TIM1_CH4_Pin GPIO_Pin_11 //小臂步进舵机
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
#define TIM8_CH1_Pin GPIO_Pin_6
#define PLANT_DIR_Pin GPIO_Pin_1 //装配盘DIR
#define PLANT_EN_Pin GPIO_Pin_15 //装配盘EN
#define MOTOR_STEP_ANGLE 1.8
#define LED_Port GPIOB
#define LED_Pin GPIO_Pin_13



#endif
