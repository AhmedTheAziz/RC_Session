/*
 * OP.h
 *
 *  Created on: Jul 19, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_OP_H_
#define INC_OP_H_
#include "main.h"
#include "utils.h"

static constexpr  uint32_t OP_50MHZ =3;
class OP
{
public:
	OP()=default;
	OP(GPIO_TypeDef * GPIO, uint8_t pin);
	void ON();
	void OFF();
	void TOGGLE();
	~OP();


private:
	GPIO_TypeDef * PORT_;
	uint8_t PIN_;
	/*inline*/ static uint8_t COUNT;
};





#endif /* INC_OP_H_ */
