#include "main.h"

#ifndef SENSOR_H_
#define SENSOR_H_

class SENSOR {
protected:
	GPIO_TypeDef* _Port;
	uint16_t _Pin;
public:
	SENSOR(GPIO_TypeDef*, uint16_t);
	int SensorRead();
	virtual ~SENSOR();
};

#endif /* SENSOR_H_ */

