/*
 * Adapter pattern
 *
 * Para entender melhor essa solução de POO foi utilizado como base um código do site 'refactoring guru'. Esse pattern
 * tem como base adaptar duas classes que não conversam diretamente entre elas, podemos fazer uma analogia a um plug de
 * tomada, onde temos diversos padrões ao redor do mundo, e para utilizar um padrão americano, por exemplo, enquanto em
 * nosso dispositivo temos um padrão brasileiro, para poder conectar fazemos o uso de adaptadores de tomada. Com
 * essa analogia podemos entender que é uma pattern para converter um padrão para um outro que o usuário não tem
 *  controle.
 *
 * Entendendo o código
 *
 * Foi criado 3 classes para o estudo. O objetivo é simular uma classe que é 'human readable' e outra que não é, o que
 * faz gerar uma terceira classe que é a adapter que faz com que a que não é 'human readable' seja convertida. Como não
 * estamos trabalhando com nenhum tipo de arquivo especifico, foi utilizado o rand() para gerar números aleatórios e,
 * foi definido que se o número for ímpar o número precisa ser somado com 1 para se tornar par, tornando o 'readable'.
 *
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


class ReadableString {
	public:
		virtual ~ReadableString() = default;
		virtual string Request(int request_type) const {
			if (request_type%2 == 0){
				return "Target: This is readable";
			} else {
				return "Target: This is unreadable";
			}
		}
};

class UnreadableString {
	public:
		int SpecificRequest() const {
			return rand();
		}
};

class StringAdapter : public ReadableString {
	private:
		UnreadableString *unreadablestr_;
		mutable string* file_status;
	public:
		StringAdapter(UnreadableString *unreadablestr) {
			unreadablestr_ = unreadablestr;
		}

		string Request(int request_type) const override {
			string warning_message;
			if (request_type%2 == 1) {
				warning_message = "Target Warning: This is a unreadable file, converting ... \n";
				request_type+=1;
			} else {
				warning_message = "";
			}
			file_status = &warning_message;
			return *file_status + string("Target: This is readable");
		}
};

int main(void) {
	srand(time(0));

	UnreadableString *unreadable_string = new UnreadableString;
        int data = unreadable_string->SpecificRequest();
        cout << data << "\n";

	ReadableString *readable_string = new ReadableString;
	cout << readable_string->Request(data) << "\n";

	StringAdapter *string_adapter = new StringAdapter(unreadable_string);
	cout << string_adapter->Request(data) << "\n";

	delete readable_string;
	delete unreadable_string;
	delete string_adapter;

	return 0;
}
