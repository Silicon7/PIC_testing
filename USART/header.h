#ifndef HEADER_H
#define	HEADER_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_conf.h"
#include "stdio.h"
#include "stdlib.h"
#include "system_stm32f4xx.h"

#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000001



void init_gpio(void);
void init_usart(uint32_t baudrate);
void init_leds(void);
void delay(unsigned long int x);
void USART_puts(USART_TypeDef* USARTx, volatile char s);
void convert_int(int x);
#endif