#include "led.h" 
#include "TIMER.h"
#include "delay.h"
#include "MOTOR.h"

int main(void)
{
	delay_init();
	LED_Init(); //调用初始化LED函数
  TIM2_PWM_Init(999, 71); //TIM2_Int_Init(u16 arr, u16 psc)，初始化定时器TIM2
	                        //定时时间=（arr+1)(psc+1)/Tclk，Tclk为内部通用定时器时钟，本例程默认设置为72MHZ
	TIM2_DIR_Init();
	PCout(0)=1;
	PCout(1)=1;
  while(1)
	{
		SetPWM(100); //设置待装入捕获比较寄存器的脉冲值，相当于不断设置TIM_Pulse
		                            //在本例程中PWM值即为一个周期(1000ms)内引脚A0输出的低电平时长(单位ms)
		                            //这个函数是给CCR寄存器赋值，CRR=PWM，CCR值/ARR值为低电平在一个周期内的占比
	}
}
