#ifndef __TIMER_H
#define __TIMER_H	
#include "sys.h"
#include "stm32f10x_tim.h"
#include "main.h"

void TIM1_PWM_Init(u16 arr, u16 psc);
void TIM2_PWM_Init(u16 arr, u16 psc);
#endif
