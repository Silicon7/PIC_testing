#include "header.h"

int main()
{
	char l = 'S';
	volatile char a;
	int i=0;
	init_gpio();
	init_leds();
	init_usart(9600);
	
	while(1)
	{
		//USART_SendData(USART2 , a);
			a = USART_ReceiveData(USART2);
		
		
		if(a == '1')
		{
			USART_SendData(USART2, a);
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			delay(10000000);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_15);
		}
		else if(a == '2')
		{
			USART_SendData(USART2, a);
			GPIO_SetBits(GPIOD , GPIO_Pin_12);
			delay(10000000);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_15);
		}
		else if(a == '3')
		{
			USART_SendData(USART2, a);
			GPIO_SetBits(GPIOD , GPIO_Pin_15);
			delay(10000000);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_15);
		}
		else
		{
			USART_SendData(USART2, a);
			GPIO_SetBits(GPIOD , GPIO_Pin_13);
			delay(10000000);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_15);
		}
		a = NULL;
			/*USART_SendData(USART2, a);
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			delay(1000000);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14); */
		
		//USART2->SR = USART2->SR & 0x3DF;
	
	}

	
/**	while(1)
	{
		//GPIO_ResetBits(GPIOD , GPIO_Pin_15);
		GPIO_SetBits(GPIOD , GPIO_Pin_14);
		delay(100000);
		GPIO_ResetBits(GPIOD , GPIO_Pin_14);
		delay(100000);
		//i++;
		
	}
	**/
	
	
	
}