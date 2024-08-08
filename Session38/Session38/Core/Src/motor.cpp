/*
 * motor.cpp
 *
 *  Created on: Jul 22, 2024
 *      Author: AHMED ABDELAZIZ
 */
#include "motor.h"

	Motor::Motor(Motor_Config * config) :config_{config}
	{
		config_->in1.OFF();
		config_->in2.OFF();
		config_->EN.OFF();
	}

	void Motor::CW()
	{
		config_->in1.ON();
		config_->in2.OFF();
		config_->EN.ON();
	}

	void Motor::CCW()
	{
		config_->in1.OFF();
		config_->in2.ON();
		config_->EN.ON();
	}

	void Motor::Stop()
	{
		config_->in1.OFF();
		config_->in2.OFF();
		config_->EN.OFF();
	}

