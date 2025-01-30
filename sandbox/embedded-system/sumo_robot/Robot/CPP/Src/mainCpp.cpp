#include "main.h"
#include "SENSOR.h"
#include "MOTOR.h"
#include "RobotDirection.h"
#include "LED.h"

extern TIM_HandleTypeDef htim1;

MOTOR M1(M1_Control2_GPIO_Port, M1_Control2_Pin, M1_Control1_GPIO_Port, M1_Control1_Pin, &htim1, 2);
MOTOR M2(M2_Control1_GPIO_Port, M2_Control1_Pin, M2_Control2_GPIO_Port, M2_Control2_Pin, &htim1, 1);

RobotDirection ROBO(&M1, &M2);

SENSOR sensor1(Sensor_1_GPIO_Port, Sensor_1_Pin);
SENSOR sensor2(Sensor_2_GPIO_Port, Sensor_2_Pin);
SENSOR sensor3(Sensor_3_GPIO_Port, Sensor_3_Pin);

LED led1(LED_1_GPIO_Port, LED_1_Pin);
LED led2(LED_2_GPIO_Port, LED_2_Pin);
LED led3(LED_3_GPIO_Port, LED_3_Pin);

int sensor_1;
int sensor_2;
int sensor_3;

void mainCpp() {
	sensor_1 = sensor1.SensorRead();
	sensor_2 = sensor2.SensorRead();
	sensor_3 = sensor3.SensorRead();

	if(sensor_1 == 1 && sensor_2 == 0 && sensor_3 == 0) {
		ROBO.forward(1, 100);
		led1.led_control(0);
		led2.led_control(1);
		led3.led_control(1);
	} else if (sensor_1 == 0 && sensor_2 == 1 && sensor_3 == 0) {
		ROBO.left(1, 100);
		led1.led_control(1);
		led2.led_control(0);
		led3.led_control(1);
	} else if (sensor_1 == 0 && sensor_2 == 0 && sensor_3 == 1) {
		ROBO.right(1, 100);
		led1.led_control(1);
		led2.led_control(1);
		led3.led_control(0);
	} else if (sensor_1 == 0 && sensor_2 == 0 && sensor_3 == 0) {
		ROBO.stop(1);
		led1.led_control(1);
		led2.led_control(1);
		led3.led_control(1);
	}
}



