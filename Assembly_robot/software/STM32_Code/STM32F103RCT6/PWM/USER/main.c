#include "led.h" 
#include "TIMER.h"
#include "delay.h"

int main(void)
{
	delay_init();
	USART1_Config();
	LED_Init(); //���ó�ʼ��LED����
  TIM2_PWM_Init(999, 71); //TIM2_Int_Init(u16 arr, u16 psc)����ʼ����ʱ��TIM2
	                        //��ʱʱ��=��arr+1)(psc+1)/Tclk��TclkΪ�ڲ�ͨ�ö�ʱ��ʱ�ӣ�������Ĭ������Ϊ72MHZ
	u16 PWM;
	u8  Direction;
  while(1)
	{
		delay_ms(1);
		if(Direction)PWM++;
		else PWM--;
		if (PWM>1000) Direction=0;
		if (PWM<1)    Direction=1;
		TIM_SetCompare1(TIM2, PWM); //���ô�װ�벶��ȽϼĴ���������ֵ���൱�ڲ�������TIM_Pulse
		                            //�ڱ�������PWMֵ��Ϊһ������(1000ms)������A0����ĵ͵�ƽʱ��(��λms)
		                            //��������Ǹ�CCR�Ĵ�����ֵ��CRR=PWM��CCRֵ/ARRֵΪ�͵�ƽ��һ�������ڵ�ռ��
	}
}
