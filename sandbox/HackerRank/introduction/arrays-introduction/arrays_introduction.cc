#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int array_index;

    	cin >> array_index;
	int user_input_array[array_index];

	for(int i = 0; i < array_index; i++) cin >> user_input_array[i];

	for (int i = array_index - 1; i >= 0; i--) cout << user_input_array[i] << " ";
	return 0;
}

