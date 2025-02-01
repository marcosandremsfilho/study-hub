#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> lines;
	vector<vector<int>> matrix;
	vector<int> response;

	int number_of_lines;
	int number_of_columns;

	int line;
	int column;

	int queries;
	int data;

	cin >> number_of_lines;
	cin >> queries;

	for(int i = 0; i < number_of_lines; i++){
		cin >> number_of_columns;
		for(int j = 0; j < number_of_columns; j++){
			cin >> data;
			lines.push_back(data);
		}
		matrix.emplace_back(lines);
		lines = vector<int>();
	}

	for (int i = 0; i < queries; i++){
		cin >> line;
		cin >> column;

		response.push_back(matrix[line][column]);
	}

	for (auto requested_integer : response) cout << requested_integer << endl;
	return 0;
}

