/*
 * Factory pattern
 *
 * Esse padrão tem como objetivo criar uma classe que abstraia a contrução de outro objeto. Essa classe é mais utilizada
 * quando se é necessário criar objetos mais complexos, facilitando a legibilidade do código em questão.
 *
 */

#include "factory_pattern.h"

InfraredSensor::InfraredSensor(std::string sensor){
	sensor_ = sensor;
}

InfraredSensor::~InfraredSensor() = default;

std::string InfraredSensor::get_sensor(){
	return sensor_;
}

Motor::Motor(std::string motor){
	motor_ = motor;
}

Motor::~Motor() = default;

std::string Motor::get_motor(){
	return motor_;
}

Robot::Robot(std::shared_ptr<InfraredSensor> infraredSensor, std::shared_ptr<Motor> motor){
	infraredSensor_ = infraredSensor;
	motor_ = motor;
}

Robot::~Robot() = default;

void Robot::do_something(){
	std::cout << "Your infraredSensor is: " << infraredSensor_->get_sensor() << std::endl;
	std::cout << "Your motor is: " << motor_->get_motor() << std::endl;
}

RobotFactory::RobotFactory(std::shared_ptr<InfraredSensor> infraredSensor, std::shared_ptr<Motor> motor){
	infraredSensor_ = infraredSensor;
	motor_ = motor;
}

RobotFactory::~RobotFactory() = default;

Robot RobotFactory::create_robot(){
	return Robot(infraredSensor_, motor_);
}

int main(void){
	std::shared_ptr<InfraredSensor> infraredSensor = std::make_shared<InfraredSensor>("JS40F");
	std::shared_ptr<Motor> motor = std::make_shared<Motor>("Silverback");

	RobotFactory robotFactory = RobotFactory(infraredSensor, motor);

	Robot sumo_robot = robotFactory.create_robot();
	sumo_robot.do_something();

	return 0;
}

