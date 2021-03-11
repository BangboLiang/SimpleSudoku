#include <iostream>
#include <math.h>

using namespace std;

bool ValidSudoku(int* sudoku, int i,int j,int size,int temp){
    //This function can judge when the board position is going to be filled with number temp,
    //whether it's valid or not.
    int x ;
    //First we examin the row and the column where temp lies in.

    for (x = 0; x <size; x++){
    //In here we don't need to avoid that x doesn't equal i or j, because the number temp is not in position (i+1,j+1)
        if (*(sudoku+ (x*size +j)) == temp || *(sudoku+ (i*size +x)) == temp){
            return false;
        }
    }
    //Then we check the smaller board (the smaller board's size is sqrt(size))
    int small_size = sqrt(size);
    int px,py;
    px = (i/small_size)*small_size;
    py = (j/small_size)*small_size;
    for (int x = px; x < px + small_size; x++){
        for (int y = py; y < py + small_size; y++){
            if (*(sudoku+ (x*size +y)) == temp){
                return false;
            }
        }
    }
    return true;
}

//This function is used to display the whole board.
void display_board(int* sudoku ,int size){
    for (int i = 0;i < size ; ++i){
        for (int j = 0; j < size; ++j){
            cout << *(sudoku+ (i*size +j)) << " ";
        }
        cout << "\n";
    }
}

//This is the solve function, we use the traceback approach to solve the problem.
bool isudokuSolver(int* sudoku, int size, int i, int j){
    //First is the destination
    if (i == size){
        display_board(sudoku,size);
        return true;
    } 
    //If we reach the end of a row, go down to the next.
    if (j == size){
        return isudokuSolver(sudoku,size,i+1,0);
    }
    //If this position has a number, go next.
    if ( *(sudoku+(i * size + j) ) != 0 ){
        return isudokuSolver(sudoku,size,i,j+1);
    }
    //Solve the problem.
    for (int temp = 1; temp <= size; ++temp){
        if (ValidSudoku(sudoku,i,j,size,temp)){
            *(sudoku + (i * size + j)) = temp;
            bool correct = isudokuSolver(sudoku,size,i,j+1);
            if (correct){
                return true;
            }
        }
    }
    //At the first code time, I made a mistake here, I forget to displace the number here.
    *(sudoku+(i*size+j)) = 0;
    return false;
}

int main(){
    cout << "Please input the sudoku problem's size.\n";
    int size;
    cin >> size;
    int sudoku[size][size];
    cout << "Please input the sudoku problem that you want to solve.\nUse number 0 to instead of empty.\n";
    for (int i = 0 ;i < size; ++i){
        for (int j = 0;j < size; ++j){
            cin >> sudoku[i][j];
        }
    }
    bool solvable = isudokuSolver(&sudoku[0][0],size,0,0);
    if (!solvable){
        cout << "No solution!\n";
    }
    return 0;
}