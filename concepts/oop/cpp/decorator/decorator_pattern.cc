/*
 *
 * Decorator pattern
 *
 * Esse padrão de orientação cria uma espécie de wrapper para as funções que a usam, adicionando uma camada de operação
 * na chamada do método e na saída do método. No código criado como exemplo temos uma tentativa de conexão com algum
 * dispositivo e quando essa conexão não é bem sucedida de primeira ele tenta reconectar.
 *
*/

#include <iostream>
#include <time.h>
#include <functional>

class PingDecorator{
	private:
		std::function<void()> func;
	public:
		PingDecorator(std::function<void()> f) : func(f){}

		void ping_emulation(){
			srand(time(0));

			int random = rand();

			if(random%2 == 1) {
				std::cout << "Connection error | Reconnecting ..." << std::endl;
				std::cout << "Connected" << std::endl;
			} else {
				std::cout << "Device connected" << std::endl;
			}
		}
		void operator()(){
			ping_emulation();
			func();
		}
};

void device_command(){
	std::cout << "Turn on" << std::endl;
}

int main(void){
	PingDecorator decoratedConnection(device_command);

	decoratedConnection();

	return 0;
}
