/*
 * output.h
 *
 *  Created on: Jul 19, 2024
 *      Author: USER
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_
#include "main.h"

static constexpr uint32_t OUTPUT_HIGH_SPEED = 3;
static constexpr uint32_t BITS_PER_PIN = 4;
static constexpr uint32_t BITS_PER_REG = 32;
static constexpr uint32_t PINS_PER_REG = 8;

class Output
{
public:
	Output(GPIO_TypeDef * GPIO, uint8_t pin)
				:port_{GPIO}, pin_{pin}
	{
		if(pin_ < PINS_PER_REG)
		{
			port_->CRL = (OUTPUT_HIGH_SPEED<<pin_*BITS_PER_PIN);
		}
		else
		{
			port_->CRH = (OUTPUT_HIGH_SPEED<<((pin_*BITS_PER_PIN)-BITS_PER_REG));
		}
		Off();
	}
	~Output()
	{
		Off();
	}
	void On()
	{
		port_->ODR |= (1<<pin_);
	}

	void Off()
	{
		port_->ODR &=~ (1<<pin_);
	}

	void Toggle()
	{
		port_->ODR ^= (1<<pin_);
	}
	private:
	GPIO_TypeDef *port_ ;
	uint8_t pin_;
};




#endif /* INC_OUTPUT_H_ */
