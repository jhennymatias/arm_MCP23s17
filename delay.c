#include "LPC17xx.h"
#include "delay.h"



#define ST_CTRL     (*((volatile unsigned long*)0xE000E010)) //page 783
volatile unsigned long sysTickCounter;

//tratador de interrupcao
void SysTick_Handler(void)
{
	if (sysTickCounter != 0x00) sysTickCounter--;
}

void yes_timer()
{
	ST_CTRL |= 1<<1; // enable IRQ interrupt
	ST_CTRL |= 1;   // enable systick	
}
void no_timer()
{
	ST_CTRL &= 0xFFFFFFFC; // enable IRQ interrupt
}
void delay_init(void)
{
} 
void delay_us(uint32_t n)
{
	no_timer();
	SysTick_Config(SystemCoreClock / 1000000);
	sysTickCounter = n;
	yes_timer();
	while (sysTickCounter != 0);
}
 
void delay_ms(uint32_t n)
{
	no_timer();
	SysTick_Config(SystemCoreClock / 1000);
	sysTickCounter = n;
	yes_timer(); 
	while (sysTickCounter != 0);
}


