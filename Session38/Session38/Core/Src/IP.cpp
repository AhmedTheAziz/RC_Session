/*
 * IP.cpp
 *
 *  Created on: Jul 20, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "IP.h"

uint32_t IP::COUNT;


	IP::IP(GPIO_TypeDef * GPIO, uint8_t pin) : PORT_{GPIO}, PIN_{pin}
	{

		if(COUNT ==0)
		{
	PORT_->CRL =0x00000000;
	PORT_->CRH =0x00000000;
		}
		COUNT++;
		if(PIN_ < PIN_per_REG)
		{
			PORT_->CRL |=(IP_Floating<<(PIN_* BIT_per_PIN));
		}
		else
		{
			PORT_->CRH |=(IP_Floating<<((PIN_* BIT_per_PIN)-BIT_per_REG));
		}
	}
	//to make it bool
	/*
	 return (PORT_->IDR>>PIN_)&1;
	 **/
	uint32_t IP::GetStatus()
	{
		return PORT_->IDR &PIN_;
	}

	bool IP::Getstatus()
	{
		 return (PORT_->IDR>>PIN_)&1;

	}

	IP::~IP()
	{}


