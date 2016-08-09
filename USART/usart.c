#include "header.h"

void delay(unsigned long int x)
{
	int m;
	for(m=0; m<x; m++)
	{}
}

void init_gpio(void)
{
	GPIO_InitTypeDef gpio_init_struct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	gpio_init_struct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;

	gpio_init_struct.GPIO_Mode = GPIO_Mode_AF;
	gpio_init_struct.GPIO_OType = GPIO_OType_PP;
	gpio_init_struct.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA , &gpio_init_struct);
}

void init_leds(void)
{
	GPIO_InitTypeDef led_struct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	led_struct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 | GPIO_Pin_12;
	led_struct.GPIO_Mode = GPIO_Mode_OUT;
	led_struct.GPIO_OType = GPIO_OType_PP;
	led_struct.GPIO_PuPd = GPIO_PuPd_UP;
	led_struct.GPIO_Speed = GPIO_Fast_Speed;
	
	GPIO_Init(GPIOD , &led_struct);
}


void init_usart(uint32_t baudrate)
{
	USART_InitTypeDef uart_struct; 
	USART_ClockInitTypeDef uart_clk;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	
	uart_struct.USART_BaudRate = baudrate;
	uart_struct.USART_WordLength = USART_WordLength_8b;
	uart_struct.USART_StopBits = USART_StopBits_1;
	uart_struct.USART_Parity = USART_Parity_No;
	uart_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	uart_struct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	//uart_struct.USART_Mode = USART_Mode_Rx;
	
	//USART_ClockStructInit(&uart_clk);
	
	GPIO_PinAFConfig(GPIOA,	GPIO_PinSource2 , GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA,	GPIO_PinSource3 , GPIO_AF_USART2);
	//USART_OverSampling8Cmd(USART2 , ENABLE);
	USART_Init(USART2 , &uart_struct);
	
	USART_Cmd(USART2, ENABLE);
}
void USART_puts(USART_TypeDef* USARTx, volatile char s){

	//while(*s){
	// wait until data register is empty
	while( !(USARTx->SR & 0x00000040) )
	{}		
		USART_SendData(USARTx,s);
	//	*s++;
	//}!
}
void convert_int(int x)
{
	if(x<0)
	{
		x = x*(-1);
		USART_puts(USART2,'-');
	}
	
    if(x>=10)
        convert_int(x/10);

    x = x%10;
    USART_puts(USART2,x+'0');
}
