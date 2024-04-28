/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitTypeDef GPIO_TIM2_InitStruct = {0};	
	GPIO_InitTypeDef GPIO_SERVO_InitStruct = {0};
	GPIO_InitTypeDef GPIO_PLANT_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  /*Configure GPIO pin Output Level */

  /*GPIOC */
  GPIO_InitStruct.Pin = PLANT_DIR_Pin|MOTOR1_AIN_1_Pin|MOTOR1_AIN_2_Pin|MOTOR2_BIN_1_Pin|PLANT_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(PLANT_Port, &GPIO_InitStruct);

  /*GPIOB */
  GPIO_InitStruct.Pin = TRANS_Pin|MOTOR3_AIN_1_Pin|MOTOR3_AIN_2_Pin|MOTOR4_BIN_1_Pin|MOTOR4_BIN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*GPIOD*/
  GPIO_InitStruct.Pin = MOTOR2_BIN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(MOTOR2_BIN_2_Port, &GPIO_InitStruct);

	/*TIM2 GPIOA*/
  GPIO_TIM2_InitStruct.Pin = TIM2_CH1_Pin|TIM2_CH2_Pin|TIM2_CH3_Pin|TIM2_CH4_Pin;
  GPIO_TIM2_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_TIM2_InitStruct.Pull = GPIO_NOPULL;
  GPIO_TIM2_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TIM2_Port, &GPIO_TIM2_InitStruct);
	 
	/*TIM3 GPIOA*/
  GPIO_SERVO_InitStruct.Pin = TIM3_CH1_Pin|TIM3_CH2_Pin;
  GPIO_SERVO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_SERVO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_SERVO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TIM3_CH12_Port, &GPIO_SERVO_InitStruct);
	
	/*TIM3 GPIOB*/
  GPIO_PLANT_InitStruct.Pin = TIM3_CH3_Pin;
  GPIO_PLANT_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_PLANT_InitStruct.Pull = GPIO_NOPULL;
  GPIO_PLANT_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(TIM3_CH3_Port, &GPIO_PLANT_InitStruct);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
