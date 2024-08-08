//#include "OP.h"
//#include "main.h"
//#include "IP.h"
//#include "motor.h"
#include "robot.h"
/*
 Session39 Implementations
 name: RObot Kit Motor.
 Include only OP.h
 when copied to the Session39 Dir.
 Robot_Controlled_via_Bluetooth
 */
//Function for only CW Movement

/*void Motor1_CW(OP &M_in1, OP&M_in2, OP&M_en)
{
	M_in1.ON();
	M_in2.OFF();
	M_en.ON();
}
*/
//Struct for PINs to be config.
/*
struct Motor_Config
{
	OP in1;
	OP in2;
	OP EN;
};

//struct to Move a single Motor..

struct Motor //Motor::
{
	Motor(Motor_Config * config) :config_{config}
	{
		config_->in1.OFF();
		config_->in2.OFF();
		config_->EN.OFF();
	}

	void CW()
	{
		config_->in1.ON();
		config_->in2.OFF();
		config_->EN.ON();
	}

	void CCW()
	{
		config_->in1.OFF();
		config_->in2.ON();
		config_->EN.ON();
	}

	void Stop()
	{
		config_->in1.OFF();
		config_->in2.OFF();
		config_->EN.OFF();
	}

	Motor_Config * config_;
};
*/

//OBJ/ Instant of motor_config to set PINS for each in1,in2 &EN
Motor_Config m1_config
{
	{GPIOA,5},
	{GPIOB,1},
	{GPIOA,6}
};
//OBJ/ Instant of motor_config to set PINS for each in1,in2 &EN
Motor_Config m2_config
{
	{GPIOA,4},
	{GPIOA,0},
	{GPIOB,0}
};

int main()
{

	//Enable RCC
	RCC->APB2ENR=(1<<2|(1<<3));

	//CONFIG AND SET the old way
	/*OP M1_in1(GPIOA,5);
	OP M1_in2(GPIOB,1);
	OP M1_EN(GPIOA,6);*/

	Motor m1(&m1_config); // obj of Motor that has the name m1 and adress of m1_config.
	Motor m2(&m2_config); // obj of Motor that has the name m2 and adress of m2_config.
	Robot robot(&m1,&m2);

	while (1)
	{
/*
 * @ first we made Motor_CW Function but it's not very efficient,
 *  it's better to make a Struct with CW,CCW &Stop Functions such as Motor
 * Motor_CW(M1_in1,M1_in2,M1_EN);
 */

	//using struct Motor
	/*	m1.CW();
		m2.CCW();*/

	// Using Class Robot
		robot.Forward();

	}

return 0;
}
