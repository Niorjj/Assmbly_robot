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
#define LSE_IN_Pin GPIO_PIN_14
#define LSE_IN_GPIO_Port GPIOC
#define LSE_OUT_Pin GPIO_PIN_15
#define LSE_OUT_GPIO_Port GPIOC
#define HSE_IN_Pin GPIO_PIN_0
#define HSE_IN_GPIO_Port GPIOD
#define HSE_OUT_Pin GPIO_PIN_1
#define HSE_OUT_GPIO_Port GPIOD
#define PLANT_DIR_Pin GPIO_PIN_1
#define PLANT_DIR_GPIO_Port GPIOC
#define PLANT_EN_Pin GPIO_PIN_2
#define PLANT_EN_GPIO_Port GPIOC
#define MOTOR1_AIN_1_Pin GPIO_PIN_10
#define MOTOR1_AIN_1_GPIO_Port GPIOC
#define MOTOR1_AIN_2_Pin GPIO_PIN_11
#define MOTOR1_AIN_2_GPIO_Port GPIOC
#define MOTOR2_BIN_1_Pin GPIO_PIN_12
#define MOTOR2_BIN_1_GPIO_Port GPIOC
#define MOTOR2_BIN_2_Pin GPIO_PIN_2
#define MOTOR2_BIN_2_GPIO_Port GPIOD
#define MOTOR3_AIN_1_Pin GPIO_PIN_5
#define MOTOR3_AIN_1_GPIO_Port GPIOB
#define MOTOR3_AIN_2_Pin GPIO_PIN_6
#define MOTOR3_AIN_2_GPIO_Port GPIOB
#define MOTOR4_BIN_1_Pin GPIO_PIN_7
#define MOTOR4_BIN_1_GPIO_Port GPIOB
#define MOTOR4_BIN_2_Pin GPIO_PIN_4
#define MOTOR4_BIN_2_GPIO_Port GPIOB
#define MOTOR5_AIN_1_Pin GPIO_PIN_7
#define MOTOR5_AIN_1_GPIO_Port GPIOC
#define MOTOR5_AIN_2_Pin GPIO_PIN_8
#define MOTOR5_AIN_2_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */
#define I2C1_SDA_GPIO_Port GPIOB
#define I2C1_SDA_Pin GPIO_PIN_8
#define I2C1_SCL_GPIO_Port GPIOB
#define I2C1_SCL_Pin GPIO_PIN_9
#define USART1_TX_GPIO_Port GPIOA
#define USART1_TX_Pin GPIO_PIN_9
#define USART1_RX_GPIO_Port GPIOA
#define USART1_RX_Pin GPIO_PIN_10
#define USART3_TX_GPIO_Port GPIOB
#define USART3_TX_Pin GPIO_PIN_10
#define USART3_RX_GPIO_Port GPIOB
#define USART3_RX_Pin GPIO_PIN_11
#define TIM2_CH1_Port GPIOA //大臂步进电机
#define TIM2_CH1_Pin GPIO_PIN_0 /
#define TIM2_CH2_Port GPIOA //小臂步进电机
#define TIM2_CH2_Pin GPIO_PIN_1 
#define TIM2_CH3_Port GPIOA //底部旋转步进电机
#define TIM2_CH3_Pin GPIO_PIN_2
#define TIM2_CH4_Port GPIOA //直线模组步进电机
#define TIM2_CH4_Pin GPIO_PIN_3
#define TIM3_CH1_Port GPIOA //机械爪步进电机
#define TIM3_CH1_Pin GPIO_PIN_6 /
#define TIM3_CH2_Port GPIOA //机械爪舵机
#define TIM3_CH2_Pin GPIO_PIN_7
#define TIM3_CH3_Port GPIOB //装配盘PUL
#define TIM3_CH3_Pin GPIO_PIN_0
#define TRANS_Port GPIOB //传送带启停端
#define TRANS_Pin GPIO_PIN_1
#define PLANT_DIR_Port GPIOC //传送带启停端
#define PLANT_DIR_Pin GPIO_PIN_1
#define PLANT_EN_Port GPIOC //传送带启停端
#define PLANT_EN_Pin GPIO_PIN_2
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
