//This is the main function of the program.
//Everything starts from here. :)

#include <iostream>
#include "sudokusolver.h"

using namespace std;



int main(int argc, char const *argv[])
{
	int size;
	cout << "Welcome to iSudoku solver!,please enter the sudoku's size.\n";
	cin >> size;
	int sudoku[size][size];
	cout << "Now please enter your sudoku puzzle. Use 0 instead of blank.\n";
	for (int i = 0;i < size; ++i){
		for (int j = 0;j < size; ++j){
			cin >> sudoku[i][j];
		}
	}
	sudokusolver(&sudoku[0][0],size,0,0);
	return 0;
}