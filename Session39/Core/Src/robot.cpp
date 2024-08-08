/*
 * robot.cpp
 *
 *  Created on: Jul 22, 2024
 *      Author: AHMED ABDELAZIZ
 */

#include "robot.h" //Robot:: //Motor one is on the Right side

	Robot::Robot(Motor *m1, Motor *m2) : m1_{m1}, m2_{m2}
	{
		m1->Stop();
		m2->Stop();
	}
	void Robot::Forward()
	{
		m1_->CW();
		m2_->CCW();
	}

	void Robot::Backward()
	{
		m1_->CCW();
		m2_->CW();
	}
	void Robot::Right()
	{
		m1_->Stop();
		m2_->CCW();
	}
	void Robot::Left()
	{
		m1_->CW();
		m2_->Stop();
	}
