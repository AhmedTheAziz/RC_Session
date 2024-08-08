#include "main.h"
int main()
{
	//enable RCC
		//enable port A and B
	RCC->APB2ENR=(1<<2)|(1<<3);
	//CONf. pins
	GPIOA->CRL=(3<<4);
	GPIOB->CRL=(4<<16);

	while(1)
	{
		//bit masking
	auto btn_val=GPIOB->IDR &(1<<4); //Bit Masking
		//set pins
		if(btn_val ==0)
		{
			for(int i {0}; i<1000 ;i++); //Dummy Loop for Delay
			GPIOA->ODR =(1<<1); // pin is ON
		}
		else
		{
			GPIOA->ODR=0x0000; //pin is OFF
		}
	}
return 0;
}
