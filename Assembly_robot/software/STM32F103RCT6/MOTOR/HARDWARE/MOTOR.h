#ifndef __MOTOR_H
#define __MOTOR_H	
#include "sys.h"
#include "stm32f10x_tim.h"

void TIM2_PWM_Init(u16 arr, u16 psc);
void TIM2_DIR_Init(void);
void SetPWM(int speed);

#endif
