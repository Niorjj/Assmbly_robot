#include "led.h"

void LED_Init(void){ //LED�ƵĽӿڳ�ʼ��
	  GPIO_InitTypeDef GPIO_InitStructure; 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);       
    GPIO_InitStructure.GPIO_Pin = LED_Pin ; //ѡ��˿ںţ�0~15��all��                        
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //ѡ��IO�ӿڹ�����ʽ       
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����IO�ӿ��ٶȣ�2/10/50MHz��    
		GPIO_Init(LED_Port,&GPIO_InitStructure);			
}
