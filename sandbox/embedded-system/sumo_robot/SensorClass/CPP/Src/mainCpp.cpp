#include "main.h"
#include "SENSOR.h"
#include "LED.h"

SENSOR sensor_Direita(Sensor_Dir_GPIO_Port, Sensor_Dir_Pin);
SENSOR sensor_Centro(Sensor_Cen_GPIO_Port, Sensor_Cen_Pin);
SENSOR sensor_Esquerda(Sensor_Esq_GPIO_Port, Sensor_Esq_Pin);

LED led_1(Led_1_GPIO_Port, Led_1_Pin);
LED led_2(Led_2_GPIO_Port, Led_2_Pin);
LED led_3(Led_3_GPIO_Port, Led_3_Pin);
LED led_4(Led_4_GPIO_Port, Led_4_Pin);

int sensor1;
int sensor2;
int sensor3;

void mainCpp() {
	sensor1 = sensor_Direita.SensorRead();
	sensor2 = sensor_Centro.SensorRead();
	sensor3 = sensor_Esquerda.SensorRead();

	if(sensor1 == 1 && sensor2 == 0 && sensor3 == 0) {
		led_1.led_control(0);
		led_2.led_control(1);
		led_3.led_control(1);
		led_4.led_control(1);
	} else if (sensor1 == 0 && sensor2 == 1 && sensor3 == 0) {
		led_1.led_control(1);
		led_2.led_control(0);
		led_3.led_control(1);
		led_4.led_control(1);
	}  else if (sensor1 == 0 && sensor2 == 0 && sensor3 == 1) {
		led_1.led_control(1);
		led_2.led_control(1);
		led_3.led_control(0);
		led_4.led_control(1);
	} else {
		led_1.led_control(1);
		led_2.led_control(1);
		led_3.led_control(1);
		led_4.led_control(1);
		HAL_Delay(500);
		led_1.led_control(0);
		led_2.led_control(0);
		led_3.led_control(0);
		led_4.led_control(0);
		HAL_Delay(500);
	}
}


