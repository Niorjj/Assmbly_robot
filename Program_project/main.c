#include "stm32f4xx_hal.h"
#include "TIM.h"

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_TIM2_Init();

  // 启动定时器
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

  // 设置电机1的占空比为50%
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 500);
  // 设置电机2的占空比为75%
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 750);

  while (1)
  {


  }
}
