/*
 * RobotDirection.h
 *
 *  Created on: Jun 12, 2022
 *      Author: marco
 */
#include "main.h"
#include "MOTOR.h"

#ifndef ROBOTDIRECTION_H_
#define ROBOTDIRECTION_H_

class RobotDirection{
protected:
	MOTOR* _M1;
	MOTOR* _M2;
public:
	RobotDirection(MOTOR*, MOTOR*);
	void forward(int, int);
	void backward(int, int);
	void left(int, int);
	void right(int, int);

	virtual ~RobotDirection();
};

#endif /* ROBOTDIRECTION_H_ */
