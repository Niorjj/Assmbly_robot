#ifndef __MAIN_H
#define __MAIN_H	
#include "TIMER.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "GPIO.h"
#include "CONTROL.h"

//�ײ���ת�������
#define MOTOR1_Port
#define MOTOR1_PUL
#define MOTOR1_DIR
#define MOTOR1_EN
//ֱ��ģ�鲽�����
#define MOTOR2_Port
#define MOTOR2_PUL
#define MOTOR2_DIR
#define MOTOR2_EN
//USART4
#define UART4_Port GPIOC
#define UART4_TX_Pin GPIO_Pin_10
#define UART4_RX_Pin GPIO_Pin_11
//TIM2
#define TIM1_CH1_Pin GPIO_Pin_8 //��۲������
#define TIM1_CH4_Pin GPIO_Pin_11 //С�۲������
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
#define TIM8_CH1_Pin GPIO_Pin_6
#define PLANT_DIR_Pin GPIO_Pin_1 //װ����DIR
#define PLANT_EN_Pin GPIO_Pin_15 //װ����EN
#define MOTOR_STEP_ANGLE 1.8
#define LED_Port GPIOB
#define LED_Pin GPIO_Pin_13



#endif
