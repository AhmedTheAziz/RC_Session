
#include "robot.h"
/*
 Session39 Implementations
 name: RObot Kit Motor.
 Robot_Controlled_via_Bluetooth
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


	Motor m1(&m1_config); // obj of Motor that has the name m1 and adress of m1_config.
	Motor m2(&m2_config); // obj of Motor that has the name m2 and adress of m2_config.
	Robot robot(&m1,&m2);

	while (1)
	{

	// Using Class Robot
		robot.Forward();

	}

return 0;
}
