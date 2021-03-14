#include "display.h"
#include <iostream>

using namespace std;

void display(int* sudoku, int size){
	int x,y;
	for (x = 0; x < size; ++x){
		for (y = 0; y < size; ++y){
			cout << *(sudoku + x * size + y) << " ";
		}
		cout << "\n";
	}
}