#include "usart.h"

void USART1_Init(int Baud_rate)
{
	GPIO_InitTypeDef GPIO_InitStrue; //定义一个引脚初始化的结构体
	USART_InitTypeDef USART_InitStrue; //定义一个串口初始化的结构体
	NVIC_InitTypeDef NVIC_InitStrue; //定义一个中断优先级初始化的结构体
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); //GPIOA时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); //串口1时钟使能
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP; //A9引脚作为串口1发送数据引脚，推挽复用输出
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_9; //引脚9
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_50MHz; //作为串口发送数据引脚时该速度可以为任意
  GPIO_Init(GPIOA,&GPIO_InitStrue); //根据上面设置好的GPIO_InitStructure参数进行初始化
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING; //A10引脚作为串口1接收数据引脚，浮空输入或带上拉输入
	GPIO_InitStrue.GPIO_Pin=GPIO_Pin_10; //引脚10
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz; //作为串口接收数据引脚时该速度可以为任意
  GPIO_Init(GPIOA,&GPIO_InitStrue); //根据上面设置好的GPIO_InitStructure参数进行初始化
	
	USART_InitStrue.USART_BaudRate=Baud_rate; //定义串口波特率为115200bit/s
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //无硬件数据流控制
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx; //发送接收兼容模式
	USART_InitStrue.USART_Parity=USART_Parity_No; //无奇偶校验位
	USART_InitStrue.USART_StopBits=USART_StopBits_1; //一个停止位
	USART_InitStrue.USART_WordLength=USART_WordLength_8b; //字长为8位数据格式
	USART_Init(USART1,&USART_InitStrue);//根据上面设置USART_InitStrue参数初始化串口1
	
	USART_Cmd(USART1,ENABLE); //使能串口1
	
//	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); //使能接收中断void USART1_IRQHandler(void)
	
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn; //属于串口1中断
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE; //中断使能
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1; //抢占优先级为1级，值越小优先级越高，0级优先级最高
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1; //响应优先级为1级，值越小优先级越高，0级优先级最高
	NVIC_Init(&NVIC_InitStrue); ////根据NVIC_InitStrue的参数初始化VIC寄存器，设置串口1中断优先级
}

//  extern int x;
//	extern int y;
//	extern int l;
//	extern int r;

//串口中断函数
void USART1_IRQHandler(void)
{
		extern int LED_on;
	  extern int LED_off;
	  extern int LED_blink;
		static int i = 0;
	  u8 Res[7];
		if(USART_GetITStatus(USART1, USART_IT_RXNE) != 0) //获取串口1接收状态标志位
		{
		 Res[i++] = USART_ReceiveData(USART1);
		 if(Res[0] !=0xaa)	i=0;
		 if(i==2 && (Res[1] != 0xbb)) i=0;
		 if(i==6)
		 {
			 if(Res[6] == 0xff)
			 {
				LED_on = Res[2];
				LED_off = Res[3];
				LED_blink = Res[4];
//			 x = Res[2];
//			 y = Res[3];
//			 l = Res[4];
//			 r = Res[5];
			 }
			  i = 0;
		 }
	 }
}

//void USART1_Send_Byte(unsigned char byte)
//{
//	USART_SendData(USART1,byte);
//	while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
//}

//void UART1_Send_Str(unsigned char *s)//发送字符串 函数   应用指针 方法
//{
//   unsigned char i=0;  //定义一个局部变量  用来 发送字符串 ++运算

//   while(s[i]!='\0')  // 每个字符串结尾 都是以  \0 结尾的
//   {
//       USART_SendData(USART1,s[i]);        //通过库函数  发送数据
//       while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);  
//          i++;                 
//   }
//}
