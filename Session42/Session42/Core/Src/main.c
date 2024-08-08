#include "main.h"

#define OSC     8000000  //8 Mhz
#define msec	4000

volatile uint32_t ticks; //volatile for ticks cause ticks is unused as optimized so voaltile

//INTERRUPT Handler (don't have to write it in stm32f1xx_it.c) okay if it's deleted or delete
//or delete void SysTick_handler() function;
//written in c not c++ may cause errors so it better be removed
void SysTick_Handler() //from startup>>startup_stm32f103c8tx000.s
{
	//do something every 1ms..
	if(ticks!=0)
	{
		ticks--;
	}
}

void delay_ms(uint32_t ms)
{
	ticks = ms;
	while(ticks);
}


int main(void)
{
	//Config ports and pins
	RCC->APB2ENR |= (1<<4); // Enable GPIOC
	GPIOC->CRH=0x33333333;

	//** As long as the CPU is On SysTick is On as well no need for RCC Enable **

	//SysTick Config. for 1ms
	SysTick->CTRL =(1<<1) |(1<<2);
	//SysTick->LOAD =8000 -1; // Flag Operation takes 1 tick so -1 is set so that flag is the last tick
	SysTick->LOAD =(OSC/msec)-1;
	SysTick->CTRL |=(1<<0); // enable at last as a safety pattern

	while(1)
	{
		/*//Polling
		while(!(SysTick->CTRL &(1<<16)));
		//do somthing
		*/

		GPIOC->ODR &=~(1<<13);//Led_off();
		delay_ms(100);
		GPIOC->ODR |=(1<<13);//Led_on();
		delay_ms(100);


	}
}
