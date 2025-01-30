/*
 * Shared ptr
 * Esse é um código de exemplo de uso de um ponteiro compartilhado (shared ptr). Esse é um dos tipos de ponteiro
 * chamados de ponteiros inteligentes. Esses ponteiros são muito utilizados pelo fato de terem um inteligencia por trás
 *  que evita problemas de memória pela ausencia do 'delete' dos ponteiros criados.
 *
 * O que é o shared ptr
 *
 * O shared pointer é um ponteiro compartilhado, a cada vez que ocorre a chamada desse ponteiro abre uma contagem para
 * se mostrar a utilização dele, e quando o trecho de código fica sem escopo ele deleta automaticamente essa cópia
 * gerada.
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
void Dog::setName(std::string name){
	this->name = name;
}

void Dog::speak(){
	std::cout << "bark bark i am " << this->name << std::endl;
	return;
}

void do_something_with_the_dog(std::shared_ptr<Dog> dog, std::string dog_name){
	dog->setName(dog_name);
	dog->speak();
}

int main(void){
	std::shared_ptr<Dog> my_dogs = std::make_shared<Dog>();

	do_something_with_the_dog(my_dogs, "Barbinha");

	my_dogs->setName("Zeus");
	my_dogs->speak();
}

