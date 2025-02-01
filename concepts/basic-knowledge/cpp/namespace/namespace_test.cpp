/*
 *
 * Namespace
 *
 * É utilizado para criar seções dentro do código com o objetivo de evitar conflitos entre arquivos.
 *
 * Explicação do código
 *
 * Esse código utiliza dois espaços de namespace, um onde é chamado de 'FirstCodeArea' e outro chamado 'SecondCodeArea', ambos carregam uma função de mesmo nome
 * o motivo de não ocorrer conflito é justamente por conta de estarem em namespace diferentes. Pode se perceber que na função 'main' temos uma seleção de qual método
 * de qual namespace utilizamos a fim de não ocorrer conflito por conta dos nomes iguais.  
 *
*/
#include <iostream>
#include <stdlib.h>

namespace FirstCodeArea {
	void printMessage(){
		std::cout << "Hello from the first code area\n";
	}
}

namespace SecondCodeArea{
	void printMessage(){
		std::cout << "Hello from the second code area\n";
	}
}

int main (void) {
	FirstCodeArea::printMessage();
	SecondCodeArea::printMessage();
}
