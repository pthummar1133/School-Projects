#include <iostream>
using namespace std;

//Transposing an array

int main()
{
	cout << "Please give the array dimensions row and column: " << endl << endl;
	
	int row, column, value;
	cin >> row >> column;
	
	cout << "Now give row x column amount of values" << endl << endl;

	
	int array[row][column];
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> value;
			array[i][j] = value;
		}
	}
	
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			cout << array[j][i] << " ";
		}
	cout << endl;
	}

    return 0;
}
