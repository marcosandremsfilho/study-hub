#include <iostream>
#include <time.h>

using namespace std;



int main(void) {
	srand(time(0));

	int random = rand();
	cout <<	random << "\n";

	if(random%2 == 1) {
		cout << "É ímpar!\n";
	} else {
		cout << "É par!\n";
	return 0;
}

