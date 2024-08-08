/*
 * IP.h
 *
 *  Created on: Jul 20, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_IP_H_
#define INC_IP_H_
#include "main.h"
#include "utils.h"


static constexpr  uint32_t IP_Floating =4;
class IP
{
public:
	IP()=default;
	IP(GPIO_TypeDef * GPIO, uint8_t pin) ;
	//to make it bool
	/*
	 return (PORT_->IDR>>PIN_)&1;
	 **/
	uint32_t GetStatus();

	bool Getstatus();

	~IP();


private:
	GPIO_TypeDef * PORT_;
	uint8_t PIN_;
	/*inline*/ static uint32_t COUNT;
	};



#endif /* INC_IP_H_ */
