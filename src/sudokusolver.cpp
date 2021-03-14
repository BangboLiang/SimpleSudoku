//This is the main traceback method function of this exciting puzzle.
//This is also the most important part of the whole project.

#include <iostream>
#include "sudokusolver.h"
#include "display.h"
#include "isvalid.h"

using namespace std;

bool sudokusolver(int* sudoku, int size, int i, int j){
	//The terminate rule
	if (i == size){
		cout << "\nFound solve like this:\n";
		display(sudoku,size);
		return true;
	}
	//If a row is over,go to the next row.
	else if (j == size){
		return sudokusolver(sudoku,size,i+1,0);
	}
	//If this position is not empty.
	else if ( *(sudoku + i * size + j) != 0 ){
		return sudokusolver(sudoku,size,i,j+1);
	}
	//The normal conditon
	else{
		int temp;
		for (temp = 1; temp <= size; temp++){
			if (isvalid(sudoku,size,i,j,temp)){
				//Fill the blank and try next position.
				*(sudoku + i * size + j) = temp;
				bool correct = sudokusolver(sudoku,size,i,j+1);
				if (correct){
					//If next positions are right, we found the solution.
					return true;
				}
			}
		}
		*(sudoku + i * size + j) = 0;
		//return to the state which is blank.
	}
	return false;
}