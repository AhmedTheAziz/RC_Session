/*
 * OP.cpp
 *
 *  Created on: Jul 20, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "OP.h"

uint8_t OP::COUNT;

	OP::OP(GPIO_TypeDef * GPIO, uint8_t pin) : PORT_{GPIO}, PIN_{pin}
	{
		if(COUNT ==0)
		{
			if(COUNT ==0)
			{
		PORT_->CRL =0x00000000;
		PORT_->CRH =0x00000000;
			}
			COUNT++;
		}
		if(PIN_ < PIN_per_REG)
		{
			PORT_->CRL |=(OP_50MHZ<<(PIN_* BIT_per_PIN));
		}
		else
		{
			PORT_->CRH |=(OP_50MHZ<<((PIN_* BIT_per_PIN)-BIT_per_REG));
		}
		OFF();
	}

	void OP::ON()
	{
		PORT_->ODR |=(1<<PIN_);
	}

	void OP::OFF()
	{
		PORT_->ODR &=~(1<<PIN_);
	}
	void OP::TOGGLE()
	{
		PORT_->ODR ^=(1<<PIN_);
	}
	OP::~OP()
	{
		OFF();
	}




