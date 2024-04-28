#include "TIMER.h"

void TIM1_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIOA_InitStructure; 
	TIM_TimeBaseInitTypeDef TIM1_TimeBaseInitStrue;	
	TIM_OCInitTypeDef TIM_OCInitTypeStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); 
	
	GPIOA_InitStructure.GPIO_Pin=TIM1_CH1_Pin|TIM1_CH4_Pin;
	GPIOA_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOA_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIOA_InitStructure); 
	 
	TIM1_TimeBaseInitStrue.TIM_Period=arr; 
	TIM1_TimeBaseInitStrue.TIM_Prescaler=psc; 
	TIM1_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM1_TimeBaseInitStrue.TIM_ClockDivision=0; 
	TIM_TimeBaseInit(TIM1, &TIM1_TimeBaseInitStrue); 
	
	TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; 
	TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitTypeStrue.TIM_Pulse = 0;
	TIM_OC1Init(TIM1, &TIM_OCInitTypeStrue); 
	TIM_OC4Init(TIM1, &TIM_OCInitTypeStrue);

	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
	
	TIM_ARRPreloadConfig(TIM1, ENABLE); 
	
	TIM_Cmd(TIM1, ENABLE); 
	
}

void TIM2_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIOA_InitStructure; 
	TIM_TimeBaseInitTypeDef TIM2_TimeBaseInitStrue;	
	TIM_OCInitTypeDef TIM_OCInitTypeStrue;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	
	GPIOA_InitStructure.GPIO_Pin=TIM2_CH3_Pin|TIM2_CH4_Pin;
	GPIOA_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOA_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIOA_InitStructure); 
	 
	TIM2_TimeBaseInitStrue.TIM_Period=arr; 
	TIM2_TimeBaseInitStrue.TIM_Prescaler=psc; 
	TIM2_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM2_TimeBaseInitStrue.TIM_ClockDivision=0; 
	TIM_TimeBaseInit(TIM2, &TIM2_TimeBaseInitStrue); 
	
	TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; 
	TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitTypeStrue.TIM_Pulse = 0;

	TIM_OC3Init(TIM2, &TIM_OCInitTypeStrue);
	TIM_OC4Init(TIM2, &TIM_OCInitTypeStrue);

	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM2, ENABLE); 
	
	TIM_Cmd(TIM2, ENABLE); 
}


void TIM8_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIOC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; 	
	TIM_OCInitTypeDef TIM_OCInitTypeStrue; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE); 
	
	GPIOC_InitStructure.GPIO_Pin=TIM8_CH1_Pin;
	GPIOC_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP; 
	GPIOC_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
	GPIO_Init(GPIOC, &GPIOC_InitStructure); 
	 
	TIM_TimeBaseInitStrue.TIM_Period=arr; 
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc; 
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM_TimeBaseInitStrue.TIM_ClockDivision=0; 
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseInitStrue);
	
	TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; 
	TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitTypeStrue.TIM_Pulse = 0; 
	TIM_OC1Init(TIM8, &TIM_OCInitTypeStrue); 

	//TIM_CtrlPWMOutputs(TIM8,ENABLE);

	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	
	TIM_ARRPreloadConfig(TIM8, ENABLE); 
	
	TIM_Cmd(TIM8, ENABLE); 
}
