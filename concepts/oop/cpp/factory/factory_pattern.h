#include <iostream>
#include <memory>
#include <string>

class InfraredSensor{
	private:
		std::string sensor_;
	public:
		InfraredSensor(std::string);
		~InfraredSensor();

		std::string get_sensor(void);
};

class Motor{
	private:
		std::string motor_;
	public:
		Motor(std::string);
		~Motor();

		std::string get_motor(void);
};

class Robot{
	private:
		std::shared_ptr<InfraredSensor> infraredSensor_;
		std::shared_ptr<Motor> motor_;

	public:
		Robot(std::shared_ptr<InfraredSensor>, std::shared_ptr<Motor>);
		~Robot();

		void do_something(void);
};

class RobotFactory {
	private:
		std::shared_ptr<InfraredSensor> infraredSensor_;
		std::shared_ptr<Motor> motor_;
	public:
		RobotFactory(std::shared_ptr<InfraredSensor>, std::shared_ptr<Motor>);
		~RobotFactory();

		Robot create_robot();
};

