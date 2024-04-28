/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

//LSE��HSE
#define LSE_IN_Port GPIOC
#define LSE_IN_Pin GPIO_PIN_14
#define LSE_OUT_Port GPIOC
#define LSE_OUT_Pin GPIO_PIN_15
#define HSE_IN_Port GPIOD
#define HSE_IN_Pin GPIO_PIN_0
#define HSE_OUT_Port GPIOD
#define HSE_OUT_Pin GPIO_PIN_1
//��۲������
#define MOTOR1_AIN_Port GPIOC
#define MOTOR1_AIN_1_Pin GPIO_PIN_10
#define MOTOR1_AIN_2_Pin GPIO_PIN_11
//С�۲������
#define MOTOR2_BIN_1_Port GPIOC
#define MOTOR2_BIN_1_Pin GPIO_PIN_12
#define MOTOR2_BIN_2_Port GPIOD
#define MOTOR2_BIN_2_Pin GPIO_PIN_2
//�ײ���ת�������
#define MOTOR3_AIN_Port GPIOB
#define MOTOR3_AIN_1_Pin GPIO_PIN_5
#define MOTOR3_AIN_2_Pin GPIO_PIN_6
//ֱ��ģ�鲽�����
#define MOTOR4_BIN_Port GPIOB
#define MOTOR4_BIN_1_Pin GPIO_PIN_7
#define MOTOR4_BIN_2_Pin GPIO_PIN_4
//USART1
#define USART1_Port GPIOA
#define USART1_TX_Pin GPIO_PIN_9
#define USART1_RX_Pin GPIO_PIN_10
//USART3
#define USART3_Port GPIOB
#define USART3_TX_Pin GPIO_PIN_10
#define USART3_RX_Pin GPIO_PIN_11
//TIM2
#define TIM2_Port GPIOA 
#define TIM2_CH1_Pin GPIO_PIN_0 //��۲������
#define TIM2_CH2_Pin GPIO_PIN_1 //С�۲������
#define TIM2_CH3_Pin GPIO_PIN_2 //�ײ���ת�������
#define TIM2_CH4_Pin GPIO_PIN_3 //ֱ��ģ�鲽�����
//TIM3
#define TIM3_CH12_Port GPIOA 
#define TIM3_CH1_Pin GPIO_PIN_6//��еצ��ȡ���
#define TIM3_CH2_Pin GPIO_PIN_7//��еצ��ת���
//TRANS���ʹ�
#define TRANS_Port GPIOB //���ʹ���ͣ��
#define TRANS_Pin GPIO_PIN_1
//PLANTװ��Բ��
#define TIM3_CH3_Port GPIOB //װ����PUL
#define TIM3_CH3_Pin GPIO_PIN_0
#define PLANT_Port GPIOC 
#define PLANT_DIR_Pin GPIO_PIN_1 //װ����DIR
#define PLANT_EN_Pin GPIO_PIN_2 //װ����EN
//LED
#define LED_Port GPIOB
#define LED_Pin GPIO_PIN_13
#define LED_KEY_Pin GPIO_PIN_14
#define MOTOR_STEP_ANGLE 1.8
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
