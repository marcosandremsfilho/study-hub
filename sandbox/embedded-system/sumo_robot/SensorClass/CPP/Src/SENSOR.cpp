#include "main.h"
#include "SENSOR.h"

SENSOR :: SENSOR(GPIO_TypeDef* Port, uint16_t Pin) {
	_Port = Port;
	_Pin = Pin;

}

int SENSOR :: SensorRead() {
	int value;

	value = HAL_GPIO_ReadPin(_Port, _Pin);

	return value;
}

SENSOR::~SENSOR() {
	// TODO Auto-generated destructor stub
}

