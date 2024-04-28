#ifndef __MAIN_H
#define __MAIN_H	
#include "TIMER.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "GPIO.h"
#include "CONTROL.h"

//��۲������
#define MOTOR1_AIN_Port GPIOB
#define MOTOR1_AIN_1_Pin GPIO_Pin_3
#define MOTOR1_AIN_2_Pin GPIO_Pin_4
#define MOTOR2_BIN_1_Pin GPIO_Pin_5
//С�۲������
#define MOTOR2_BIN_2_Port GPIOC
#define MOTOR2_BIN_2_Pin GPIO_Pin_14
//�ײ���ת�������
#define MOTOR3_AIN_Port GPIOB
#define MOTOR3_AIN_1_Pin GPIO_Pin_5
#define MOTOR3_AIN_2_Pin GPIO_Pin_6
//ֱ��ģ�鲽�����
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
#define TIM2_CH1_Pin GPIO_Pin_8 //��۲������
#define TIM2_CH2_Pin GPIO_Pin_11 //С�۲������
#define TIM2_CH3_Pin GPIO_Pin_2 //��еצ��ת���
#define TIM2_CH4_Pin GPIO_Pin_3 //��еצ��ȡ���
//TIM4
#define TIM4_CH12_Port GPIOB 
#define TIM4_CH1_Pin GPIO_Pin_6//�ײ���ת�������
#define TIM4_CH2_Pin GPIO_Pin_7//ֱ��ģ�鲽�����
//TRANS���ʹ�
#define TRANS_Port GPIOB //���ʹ���ͣ��
#define TRANS_Pin GPIO_Pin_1
//PLANTװ��Բ��
#define PLANT_Port GPIOC
#define TIM8_CH1_Pin GPIO_Pin_6
#define PLANT_DIR_Port GPIOA
#define PLANT_DIR_Pin GPIO_Pin_1 //װ����DIR
#define PLANT_EN_Pin GPIO_Pin_15 //װ����EN
//LED
#define LED_Port GPIOB
#define LED_Pin GPIO_Pin_13
#define LED_KEY_Pin GPIO_Pin_14
#define MOTOR_STEP_ANGLE 1.8


#endif
