#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
uint8_t RxData;
int a[9];
int	i=0;

int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 1, "zb:");
	OLED_ShowString(2, 1, "gd:");
	OLED_ShowString(3, 1, "jd:");
	OLED_ShowString(4, 1, "jd:");
	
	Serial_Init();
	
	while (1)
	{  
		if (Serial_GetRxFlag() == 1)
		{
			RxData = Serial_GetRxData();
			Serial_SendByte(RxData);
			a[i]=RxData;
			i+=1;
		}
		
		if(i==9){
	        OLED_ShowHexNum(1,4,a[0],2);
	        OLED_ShowHexNum(1,7,a[1],2);
	        OLED_ShowHexNum(2,4,a[2],2);
	        OLED_ShowHexNum(3,4,a[3],2);
	        OLED_ShowHexNum(3,6,a[4],2);
		    OLED_ShowHexNum(3,8,a[5],2);
			OLED_ShowHexNum(4,4,a[6],2);
			OLED_ShowHexNum(4,6,a[7],2);
			OLED_ShowHexNum(4,8,a[8],2);
			
		}		
	}
	
}
