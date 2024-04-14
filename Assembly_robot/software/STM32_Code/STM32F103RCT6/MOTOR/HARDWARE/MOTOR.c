#include "MOTOR.h"

void TIM2_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ�����ų�ʼ���Ľṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //����һ����ʱ�жϵĽṹ��	
	TIM_OCInitTypeDef TIM_OCInitTypeStrue; //����һ��PWM����Ľṹ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��GPIOAʱ�ӣ���STM32��ʹ��IO��ǰ��Ҫʹ�ܶ�Ӧʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʹ��ͨ�ö�ʱ��2ʱ�ӣ�A0���Ŷ�ӦTIM2CHN1
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP; //�����������ģʽ����ʱ������ΪA0���Ÿ��ù���
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //�������������ٶ�Ϊ50MHZ
  GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ������GPIOA0
	 
	TIM_TimeBaseInitStrue.TIM_Period=arr; //����ģʽΪ���ϼ���ʱ����ʱ����0��ʼ����������������arrʱ������ʱ�жϷ�����
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc; //Ԥ��Ƶϵ��������ÿһ��������ʱ��
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up; //����ģʽ�����ϼ���
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1; //һ�㲻ʹ�ã�Ĭ��TIM_CKD_DIV1
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStrue); //����TIM_TimeBaseInitStrue�Ĳ�����ʼ����ʱ��TIM2
	
	TIM_OCInitTypeStrue.TIM_OCMode=TIM_OCMode_PWM2; //PWMģʽ2������ʱ����������TIM_Pulseʱ����ʱ����ӦIO�����Ч��ƽ
	TIM_OCInitTypeStrue.TIM_OCPolarity=TIM_OCNPolarity_High; //�����Ч��ƽΪ�ߵ�ƽ
	TIM_OCInitTypeStrue.TIM_OutputState=TIM_OutputState_Enable; //ʹ��PWM���
	TIM_OCInitTypeStrue.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OC1Init(TIM2, &TIM_OCInitTypeStrue); //��TIM_OCInitTypeStrue������ʼ����ʱ��2ͨ��1

	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable); //CH1Ԥװ��ʹ��

	TIM_ARRPreloadConfig(TIM2, ENABLE); //CH1Ԥװ��ʹ��
	
	TIM_Cmd(TIM2, ENABLE); //ʹ�ܶ�ʱ��TIM2
}

void TIM2_DIR_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ�����ų�ʼ���Ľṹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //ʹ��GPIOAʱ�ӣ�GPIOA������APB2ʱ���£���STM32��ʹ��IO��ǰ��Ҫʹ�ܶ�Ӧʱ��
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1; //����4
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //�����������ģʽΪ�������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //��������ٶ�Ϊ50MHZ
	GPIO_Init(GPIOC, &GPIO_InitStructure); //�����������úõ�GPIO_InitStructure��������ʼ������GPIOA_PIN4
	
	GPIO_SetBits(GPIOC, GPIO_Pin_0|GPIO_Pin_1); //��ʼ����������GPIOA4Ϊ�ߵ�ƽ
}

void SetPWM(int speed)
{
	TIM_SetCompare1(TIM2,speed);
}

