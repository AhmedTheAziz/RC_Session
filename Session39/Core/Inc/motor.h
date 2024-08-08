/*
 * motor.h
 *
 *  Created on: Jul 22, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
#include "OP.h"


//Struct for PINs to be config.
struct Motor_Config
{
	OP in1;
	OP in2;
	OP EN;
};

//struct to Move a single Motor..
struct Motor //Motor::
{
	Motor(Motor_Config * config);
	void CW();

	void CCW();
	void Stop();

	Motor_Config * config_;
};



#endif /* INC_MOTOR_H_ */
