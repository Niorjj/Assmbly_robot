#include "stm32f10x.h"
#include <stdio.h>
#include "sys.h"
#include "led.h"
#include "pwm.h"
#include "usart.h"
#include "delay.h"


u8 LED_on ,LED_off ,LED_blink;
//int x;//目标点x轴位置
//int y;//目标点y轴位置
//int l;//目标点距离
//int r;//目标点旋转角度


int main(void)
{

//	u16 led0pwmval=0;
//	u8 dir=1;	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//初始化中断向量分组为2:2
	USART1_Init(115200);//初始化串口1的波特率为115200.（使用printf一定要初始化）
	LED_Init();//LED初始化
	TIM3_PWM_Init(500-1,72-1);	//不分频。PWM频率=1000000/500=2Khz，一个周期2khz，频率低时看见LED闪烁，并不断变亮，高频时看不见闪烁。
	
	while(1)
	{
		if(LED_on == 0x01){
			printf("开灯\r\n");
			GPIO_ResetBits(LED_Port,LED_Pin);
		}
		if(LED_off == 0x02){
			printf("关灯\r\n");
			GPIO_SetBits(LED_Port,LED_Pin);
		}
		if(LED_blink == 0x01){
			printf("开灯\r\n");
			GPIO_ResetBits(LED_Port,LED_Pin);
			delay_ms(1000);
			GPIO_SetBits(LED_Port,LED_Pin);
			delay_ms(1000);
		}
		delay_ms(1000);
		
		
		
		
//		delay_ms(10);	 //延时是为了呼吸灯的呼吸现象更明显
//		if(dir)
//			led0pwmval++;//LED亮度不断加
//		else 
//			led0pwmval--;//LED亮度不断减

// 		if(led0pwmval>400)//LED有效电平为0-400
//			dir=0;
//		if(led0pwmval==50)
//			dir=1;										 
//		TIM_SetCompare1(TIM3,led0pwmval);	//设置占空比，通道二，led0pwmval为CCR2，不断移动CCR2，实现占空比调制
//		//TIM_SetCompare2是通道2，如果是别的通道要改这里！！！
//		
	}
}

