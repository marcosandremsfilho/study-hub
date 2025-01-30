#include "main.h"
#include "MOTOR.h"
#include "RobotDirection.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

MOTOR M1(MOTOR1_Pin1_GPIO_Port, MOTOR1_Pin1_Pin, MOTOR1_Pin2_GPIO_Port, MOTOR1_Pin2_Pin, &htim1, 1);
MOTOR M2(MOTOR2_Pin1_GPIO_Port, MOTOR2_Pin1_Pin, MOTOR2_Pin2_GPIO_Port, MOTOR2_Pin2_Pin, &htim1, 2);
RobotDirection robo(&M1,&M2);

void mainCpp() {
	robo.forward(1000, 50);
	robo.right(1000, 100);
	robo.backward(1000, 125);
	robo.left(1000, 255);
}





















//caios2
