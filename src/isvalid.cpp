//This is the function of judging this fill is a valid or not.
//while judging the board, the number has not been filled in.
#include <math.h>

bool isvalid (int* sudoku, int size, int i, int j, int temp){
	//Firstly, judge the rows and columns.
	for (int x = 0; x < size; ++x){
		if ( *(sudoku + size * x + j) == temp || *(sudoku + size * i + x) == temp ){
			return false;
		}
	}
	//Next, judge the small boards(3x3 or other smaller size).
	int small_size = sqrt(size);
	int px,py;
	px = (i/small_size) * small_size;
	py = (j/small_size) * small_size;
	for (int x = px; x < px+small_size; ++x){
		for (int y = py; y < py+small_size; ++y){
			if (*(sudoku + x * size + y) == temp){
				return false;
			}
		}
	}
	return true;
}