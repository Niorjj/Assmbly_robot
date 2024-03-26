#include "led.h" 
#include "TIMER.h"
#include "delay.h"
#include "MOTOR.h"

int main(void)
{
	delay_init();
	LED_Init(); //���ó�ʼ��LED����
  TIM2_PWM_Init(999, 71); //TIM2_Int_Init(u16 arr, u16 psc)����ʼ����ʱ��TIM2
	                        //��ʱʱ��=��arr+1)(psc+1)/Tclk��TclkΪ�ڲ�ͨ�ö�ʱ��ʱ�ӣ�������Ĭ������Ϊ72MHZ
	TIM2_DIR_Init();
	PCout(0)=1;
	PCout(1)=1;
  while(1)
	{
		SetPWM(100); //���ô�װ�벶��ȽϼĴ���������ֵ���൱�ڲ�������TIM_Pulse
		                            //�ڱ�������PWMֵ��Ϊһ������(1000ms)������A0����ĵ͵�ƽʱ��(��λms)
		                            //��������Ǹ�CCR�Ĵ�����ֵ��CRR=PWM��CCRֵ/ARRֵΪ�͵�ƽ��һ�������ڵ�ռ��
	}
}
