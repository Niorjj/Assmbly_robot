#ifndef __MAIN_H
#define __MAIN_H	
#include "TIMER.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "GPIO.h"
#include "CONTROL.h"

//�ײ���ת�������
#define MOTOR_Port GPIOB
#define MOTOR_PUL GPIO_Pin_3
#define MOTOR_DIR GPIO_Pin_4
#define MOTOR_EN GPIO_Pin_5
//USART4
#define USART1_Port GPIOA
#define USART1_TX_Pin GPIO_Pin_9
#define USART1_RX_Pin GPIO_Pin_10
//TIM
#define TIM1_CH1_Pin GPIO_Pin_8 //��۶��
#define TIM1_CH4_Pin GPIO_Pin_11 //С�۶��
#define TIM2_CH2_Pin GPIO_Pin_1 //�ײ���ת���
#define TIM2_CH3_Pin GPIO_Pin_2 //��еצ��ת���
#define TIM2_CH4_Pin GPIO_Pin_3 //��еצ��ȡ���
//TRANS���ʹ�PB14
#define TRANS_Pin GPIO_Pin_14
//PLANTװ��Բ��PB15 PB10 PB11 
#define PLANT_PUL_Pin GPIO_Pin_15
#define PLANT_DIR_Pin GPIO_Pin_10//װ����DIR
#define PLANT_EN_Pin GPIO_Pin_11 //װ����EN
#define MOTOR_STEP_ANGLE 1.8
#define lengthpercir 0.4
#define LED_Port GPIOB
#define LED_Pin GPIO_Pin_13


#endif
