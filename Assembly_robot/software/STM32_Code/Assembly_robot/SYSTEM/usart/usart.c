#include "sys.h"
#include "usart.h"	  
#include "string.h"

#define PACKET_LENGTH 15
uint8_t RX_Buffer[PACKET_LENGTH];
uint8_t RX_Index =0;
uint8_t RX_Flag = 0;

void USART_puts(USART_TypeDef* USARTx, volatile char *s)
{
    while(*s)
    {
        USART_SendData(USARTx, *s);
        while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); 
        s++;
    }
}
void USART1_Init(uint32_t bound)
{
  GPIO_InitTypeDef GPIO_InitStrue; 
	USART_InitTypeDef USART_InitStrue; 
	NVIC_InitTypeDef NVIC_InitStrue; 
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_AF_PP; 
	GPIO_InitStrue.GPIO_Pin=USART1_TX_Pin; 
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
  GPIO_Init(GPIOA,&GPIO_InitStrue); 
	
	GPIO_InitStrue.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStrue.GPIO_Pin=USART1_RX_Pin; 
	GPIO_InitStrue.GPIO_Speed=GPIO_Speed_10MHz;
  GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	USART_InitStrue.USART_BaudRate=bound; 
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None; 
	USART_InitStrue.USART_Mode=USART_Mode_Tx|USART_Mode_Rx; 
	USART_InitStrue.USART_Parity=USART_Parity_No; 
	USART_InitStrue.USART_StopBits=USART_StopBits_1; 
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStrue);
	
	USART_Cmd(USART1,ENABLE); 
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); 
	
	NVIC_InitStrue.NVIC_IRQChannel=USART1_IRQn; 
	NVIC_InitStrue.NVIC_IRQChannelCmd=ENABLE; 
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority=1; 
	NVIC_Init(&NVIC_InitStrue); 
}

void processPacket(uint8_t *data, uint8_t length)
{
		j1 = (uint16_t)RX_Buffer[2];
		j2 = (uint16_t)RX_Buffer[2];
		j3 = (uint16_t)RX_Buffer[2];
		j4 = (uint16_t)RX_Buffer[2];
    USART_puts(USART1, "Received packet: ");
    for(int i = 0; i < length; i++)
    {
        USART_SendData(USART1, data[i]);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); 
    }
    USART_puts(USART1, "\r\n");
}

void USART1_IRQHandler(void)
{
	 if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) // Check if received data available
    {
        uint8_t data = USART_ReceiveData(USART1); // Read the received data
        
        if(RX_Flag == 0 && data == 0xAA)
        {
            RX_Flag = 1; // Set frame start flag if received byte is frame start marker
            RX_Index = 0; // Reset buffer index
        }
        else if(RX_Flag == 1 && RX_Index < PACKET_LENGTH)
        {
            RX_Buffer[RX_Index++] = data; // Store data in buffer
            
            if(RX_Index == PACKET_LENGTH)
            {
                // Check if the last two bytes are "\r\n"
                if(RX_Buffer[PACKET_LENGTH - 2] == '\r' && RX_Buffer[PACKET_LENGTH - 1] == '\n')
                {
                    // Process received packet here
                    // Example: call a function to handle the received packet
                    processPacket(RX_Buffer, PACKET_LENGTH);
                    RX_Flag = 0; // Reset frame start flag for next packet reception
                }
                else
                {
                    // Discard incomplete packet and reset buffer
                    RX_Index = 0;
                    RX_Flag = 0;
                }
            }
        }
        else
        {
            // Discard data if frame start flag is not set or buffer is full
        }
    }
  USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}



