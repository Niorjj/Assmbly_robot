#include "stm32f10x.h"
#include <stdio.h>
#include "sys.h"
#include "led.h"
#include "pwm.h"
#include "usart.h"
#include "delay.h"


u8 LED_on ,LED_off ,LED_blink;
//int x;//Ŀ���x��λ��
//int y;//Ŀ���y��λ��
//int l;//Ŀ������
//int r;//Ŀ�����ת�Ƕ�


int main(void)
{

//	u16 led0pwmval=0;
//	u8 dir=1;	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//��ʼ���ж���������Ϊ2:2
	USART1_Init(115200);//��ʼ������1�Ĳ�����Ϊ115200.��ʹ��printfһ��Ҫ��ʼ����
	LED_Init();//LED��ʼ��
	TIM3_PWM_Init(500-1,72-1);	//����Ƶ��PWMƵ��=1000000/500=2Khz��һ������2khz��Ƶ�ʵ�ʱ����LED��˸�������ϱ�������Ƶʱ��������˸��
	
	while(1)
	{
		if(LED_on == 0x01){
			printf("����\r\n");
			GPIO_ResetBits(LED_Port,LED_Pin);
		}
		if(LED_off == 0x02){
			printf("�ص�\r\n");
			GPIO_SetBits(LED_Port,LED_Pin);
		}
		if(LED_blink == 0x01){
			printf("����\r\n");
			GPIO_ResetBits(LED_Port,LED_Pin);
			delay_ms(1000);
			GPIO_SetBits(LED_Port,LED_Pin);
			delay_ms(1000);
		}
		delay_ms(1000);
		
		
		
		
//		delay_ms(10);	 //��ʱ��Ϊ�˺����Ƶĺ������������
//		if(dir)
//			led0pwmval++;//LED���Ȳ��ϼ�
//		else 
//			led0pwmval--;//LED���Ȳ��ϼ�

// 		if(led0pwmval>400)//LED��Ч��ƽΪ0-400
//			dir=0;
//		if(led0pwmval==50)
//			dir=1;										 
//		TIM_SetCompare1(TIM3,led0pwmval);	//����ռ�ձȣ�ͨ������led0pwmvalΪCCR2�������ƶ�CCR2��ʵ��ռ�ձȵ���
//		//TIM_SetCompare2��ͨ��2������Ǳ��ͨ��Ҫ���������
//		
	}
}

