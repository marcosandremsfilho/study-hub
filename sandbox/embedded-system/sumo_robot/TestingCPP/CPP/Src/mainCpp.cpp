/*
 * mainCpp.cpp
 *
 *  Created on: Jun 9, 2022
 *      Author: marco
 */
#include "main.h"
#include "LED.h"

LED Led_1(GPIO_Led1_GPIO_Port, GPIO_Led1_Pin);
LED Led_2(GPIO_Led2_GPIO_Port, GPIO_Led2_Pin);
LED Led_3(GPIO_Led3_GPIO_Port, GPIO_Led3_Pin);
LED Led_4(GPIO_Led4_GPIO_Port, GPIO_Led4_Pin);

void mainCpp() {

	Led_1.led_control(1);
	Led_2.led_control(0);
	Led_3.led_control(1);
	Led_4.led_control(0);
	HAL_Delay(500);
	Led_1.led_control(0);
	Led_2.led_control(1);
	Led_3.led_control(0);
	Led_4.led_control(1);
	HAL_Delay(500);
}



