#include "main.h"

#ifndef LED_H_
#define LED_H_

class LED {
private:
	GPIO_TypeDef* _Port;
	uint16_t _Pin;
public:
	LED(GPIO_TypeDef*, uint16_t);
	void led_control(int);
	virtual ~LED();
};

#endif
