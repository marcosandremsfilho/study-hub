#include "RobotDirection.h"
#include "main.h"
#include "MOTOR.h"

RobotDirection :: RobotDirection(MOTOR* M1, MOTOR* M2) {
	_M1 = M1;
	_M2 = M2;
}

void RobotDirection :: forward(int time, int PWM) {
	_M1->CW(PWM);
	_M2->CW(PWM);

	HAL_Delay(time);
}

void RobotDirection :: backward(int time, int PWM) {
	_M1->CCW(PWM);
	_M2->CCW(PWM);

	HAL_Delay(time);
}

void RobotDirection :: left(int time, int PWM) {
	_M1->CW(PWM);
	_M2->CCW(PWM);

	HAL_Delay(time);
}

void RobotDirection :: right(int time, int PWM) {
	_M1->CCW(PWM);
	_M2->CW(PWM);

	HAL_Delay(time);
}

RobotDirection::~RobotDirection() {
	// TODO Auto-generated destructor stub
}

