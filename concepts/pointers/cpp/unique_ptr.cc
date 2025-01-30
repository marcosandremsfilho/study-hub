/*
 *
 * Unique pointer
 *
 * O ponteiro único é um ponteiro criado exclusivamente para um espaço de memória, para passa-lo para outro escopo de
 * código é necessário utilizar o método 'std::move()', que permite 'mover' o ponteiro para esse outro escopo. Vale
 * ressaltar que é um ponteiro que deve ser usado com cuidado, pois a partir do momento que ele entrar em outro escopo e
 * esse escopo chegar o fim, o ponteiro será destruído, e caso esse ponteiro esteja sendo usado em pontos futuros o
 * código apresentará um erro na hora de rodar (Atenção! Ele não irá apresentar esse erro na compilação). Para contornar
 * esse problema é necessário retornar esse ponteiro para o escopo inicial.
 *
 * Obs: Esse código foi criado com o intuito de estudo, porém é aconselhável para esse caso utilizar o shared_ptr
 * (ponteiro compartilhado).
 *
*/

#include <iostream>
#include <memory>

class Dog {
	public:
		void setName(std::string);
		void speak();
	private:
		std::string name;
};

void Dog::setName(std::string name) {
	this->name = name;
}

void Dog::speak(){
	std::cout << "bark bark i am " << this->name << std::endl;
}

std::unique_ptr<Dog> do_something_with_the_dog(std::unique_ptr<Dog> dog, std::string name){
	dog->setName(name);
	dog->speak();

	return dog;
}

int main(void){
	std::unique_ptr<Dog> my_dogs = std::make_unique<Dog>();

	my_dogs = do_something_with_the_dog(std::move(my_dogs), "Naga");

	my_dogs->setName("Car");
	my_dogs->speak();
}

