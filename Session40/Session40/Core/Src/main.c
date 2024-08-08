#include "main.h"
/* For BT Connection.
 * BlueTooth App.
 * (LightBlue for IPHone)
 * (BlueTooth Terminal for Android)
 * (Bluetooth Serial Controller for Windows) [by Mocha Soft.]
 * Connect Hardware BT with MCU
 * Pair & Connect the Devices
 * Send Char.
 * */

/*For TTL Serial Connection
 * Use USB to TTL Module (CP210x) [USB to serial]
 * Connect with MCU.
 * Mount the USB Module on PC.
 * Install Driver.
 * Open APP. (Realterm)
 * determine baud rate (9600), Port of the module [from device manager]
 * Send Char.
 * */

//Defines
#define FOSC 8000000 //Freq. of OSC. is 8Mhz
#define BAUD 9600    // Baud rate 9600 for BT connection.

//Functions.
void LED_ON()
{
	GPIOC->ODR |=(1<<13);
}
void LED_OFF()
{
	GPIOC->ODR &=~(1<<13);
}

void LED_INIT()
{
	RCC->APB2ENR |=(1<<4);
	GPIOC->CRH =(3<<20);
}

void USART_sendChar (char data)
{
	USART1->DR=data &0xff; // f=15 (1111) (2^3,2^2,2^1,2^0) (8,4,2,1) total=15.
	while(!(USART1->SR &(1<<7))); //Polling waiting for data value from
}
void USART_sendString (char *data)
{
	int i=0;
	while (data[i]!= '\0')
	{
		USART_sendChar(data[i]);
		i++;
	}
}


int main(void)
{
	//Enable        AFIO     GPIOA    USART1
	RCC->APB2ENR = (1<<0) | (1<<2) | (1<<14);
	// As USART1 is using Port A pins so we must confg. GPIOA as well.
	LED_INIT();
	//Port A9 to be O/P as Alternate Function  for USART Transmission.
	GPIOA->CRH =(0x0B<<4); // B=11 (1011) (8+2+1)
	//Port A10 to be I\P Floating for USART Receiving.
	GPIOA->CRH |=(0x4<<8); // 4= (0100)
	//Test if wanted to activate both PA9 & PA10 at once
	//GPIOA->CRH=(0x4B<<4);
	//  0000   0000   0000
	//   p10    p9     p8
	// (0100) (1011) (0000)

	double usart_div = FOSC/(BAUD);
	USART1->BRR=usart_div;
	//Enable Transmission & Reception
	USART1->CR1 = (1<<2) |(1<<3);// TX and RX Enable bits
	USART1->CR1 |=(1<<13); //UART Enable
	while(1)
	{
		while(!(USART1->SR &(1<<5))); //Polling waiting for a Value @ Receiving Pin
		// ..DR-> & 0x00FF is Masking for the first 8 Bits only which are the bits needed to read.
		unsigned char control =USART1->DR &0x00FF;// Read first 8 bits and take their value to var. 'control'
		if (control =='w')
		{
			LED_ON();
			USART_sendString("LED is ON\r\n");
			// ERROR: C++ forbids Converting a string constant to 'char*'
		}
		else
		{
			LED_OFF();
			USART_sendString("LED is OFF\r\n");
		}
	}

}
