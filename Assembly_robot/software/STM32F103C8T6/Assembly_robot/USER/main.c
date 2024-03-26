#include "stm32f10x.h"
#include <stdio.h>
#include "sys.h"
#include "led.h"
#include "pwm.h"

/*
���Ҫ���ı�����ţ�����Ҫ�ҵ��������������ĸ���ʱ�����ĸ�ͨ��
Ȼ��ȥ��PWM.C������滻���ġ�
ע����STM32F103C8T6�е�
PA7��TIM3-CH2
PA6��TIM3-CH1

*/

int main(void)
{
	u16 led0pwmval=0;
	u8 dir=1;	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//��ʼ���ж���������Ϊ2:2
	uart_init(115200);//��ʼ������1�Ĳ�����Ϊ115200.��ʹ��printfһ��Ҫ��ʼ����
	LED_Init();//LED��ʼ��
	TIM3_PWM_Init(500-1,72-1);	//����Ƶ��PWMƵ��=1000000/500=2Khz��һ������2khz��Ƶ�ʵ�ʱ����LED��˸�������ϱ�������Ƶʱ��������˸��
	
	while(1)
	{
	
		delay_ms(10);	 //��ʱ��Ϊ�˺����Ƶĺ������������
		if(dir)
			led0pwmval++;//LED���Ȳ��ϼ�
		else 
			led0pwmval--;//LED���Ȳ��ϼ�

 		if(led0pwmval>400)//LED��Ч��ƽΪ0-400
			dir=0;
		if(led0pwmval==50)
			dir=1;										 
		TIM_SetCompare1(TIM3,led0pwmval);	//����ռ�ձȣ�ͨ������led0pwmvalΪCCR2�������ƶ�CCR2��ʵ��ռ�ձȵ���
		//TIM_SetCompare2��ͨ��2������Ǳ��ͨ��Ҫ���������
		
	}
}

