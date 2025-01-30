#include "LED.h"

LED::LED(GPIO_TypeDef* Port, uint16_t Pin) {
	_Port = Port;
	_Pin = Pin;
}

LED::~LED() {

}

void LED :: led_control(int state) {
	HAL_GPIO_WritePin(_Port, _Pin, (GPIO_PinState)state);
}

