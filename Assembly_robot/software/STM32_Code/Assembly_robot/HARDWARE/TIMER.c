#include "TIMER.h"

void TIM2_IRQHandler()
{
  if(TIM_GetITStatus(TIM2, TIM_IT_Update)==1) 
	{
	  PBout(13)=!PBout(13); 
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 
	}
}


void TIM2_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIOA_InitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue;	
	TIM_OCInitTypeDef TIM_OCInitTypeStrue;
	NVIC_InitTypeDef NVIC_InitStrue; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	
	GPIOA_InitStructure.GPIO_Pin=TIM2_CH1_Pin|TIM2_CH2_Pin|TIM2_CH3_Pin|TIM2_CH4_Pin;
	GPIOA_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOA_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIOA_InitStructure); 
	 
	TIM_TimeBaseInitStrue.TIM_Period=arr; 
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc; 
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM_TimeBaseInitStrue.TIM_ClockDivision=0; 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStrue); 
	
	TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; 
	TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitTypeStrue.TIM_Pulse = 0;
	TIM_OC1Init(TIM2, &TIM_OCInitTypeStrue); 
	TIM_OC2Init(TIM2, &TIM_OCInitTypeStrue);
	TIM_OC3Init(TIM2, &TIM_OCInitTypeStrue);
	TIM_OC4Init(TIM2, &TIM_OCInitTypeStrue);
	
	NVIC_InitStrue.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE; 
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1; 
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStrue);

	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	//TIM_CtrlPWMOutputs(TIM2,ENABLE);
	
	TIM_ARRPreloadConfig(TIM2, ENABLE); 
	
	TIM_Cmd(TIM2, ENABLE); 
}
void TIM4_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIOB_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; 	
	TIM_OCInitTypeDef TIM_OCInitTypeStrue; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 
	
	GPIOB_InitStructure.GPIO_Pin=TIM4_CH1_Pin|TIM4_CH2_Pin;
	GPIOB_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP; 
	GPIOB_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; 
	GPIO_Init(GPIOB, &GPIOB_InitStructure); 
	 
	TIM_TimeBaseInitStrue.TIM_Period=arr; 
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc; 
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; 
	TIM_TimeBaseInitStrue.TIM_ClockDivision=0; 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStrue);
	
	TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; 
	TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; 
	TIM_OCInitTypeStrue.TIM_Pulse = 0; 
	TIM_OC1Init(TIM4, &TIM_OCInitTypeStrue); 
	TIM_OC2Init(TIM4, &TIM_OCInitTypeStrue);

	//TIM_CtrlPWMOutputs(TIM3,ENABLE);

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable); 
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM4, ENABLE); 
	
	TIM_Cmd(TIM4, ENABLE); 
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

	//TIM_CtrlPWMOutputs(TIM3,ENABLE);

	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	
	TIM_ARRPreloadConfig(TIM8, ENABLE); 
	
	TIM_Cmd(TIM8, ENABLE); 
}
