/*
 * robot.h
 *
 *  Created on: Jul 22, 2024
 *      Author: AHMED ABDELAZIZ
 */

#ifndef INC_ROBOT_H_
#define INC_ROBOT_H_
#include "motor.h"

class Robot
{
public:
	Robot(Motor *m1, Motor *m2) ;
	void Forward();

	void Backward();
	void Right();
	void Left();
private:
	Motor *m1_;
	Motor *m2_;
};


#endif /* INC_ROBOT_H_ */
