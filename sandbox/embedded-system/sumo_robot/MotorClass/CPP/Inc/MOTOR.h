#include "main.h"

#ifndef MOTOR_H_
#define MOTOR_H_

class MOTOR {
protected:
	GPIO_TypeDef* _Port1;
	GPIO_TypeDef* _Port2;
	uint16_t _Pin1, _Pin2;
	TIM_HandleTypeDef* _htim;
	int _channel;

public:
	MOTOR(GPIO_TypeDef*, uint16_t, GPIO_TypeDef*, uint16_t, TIM_HandleTypeDef*, int);
	void CW(int);
	void CCW(int);
	void MotorOff();
	virtual ~MOTOR() { }
};

#endif
