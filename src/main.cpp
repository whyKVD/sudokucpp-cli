/**
 *  @author whyKVD
 * */

#include <iostream>
#include "sudokuGen.h"
#include "sudokuChecker.h"
#include "solver.h"

using namespace std;

void menu();

int main(int argc, char *argv[]) {

  int solvedSudoku[9][9] = {0}, mat[9][9] = {0};

  srand(time(NULL));
  
  cout << "generating sudoku" << endl;
  while (!generateSudoku(solvedSudoku)) {
    zero(solvedSudoku);
    cout << "restarting\r";
  }
  cout << endl;
  
  cout << "deleting some number from the generated sudoku" << endl;
  fillSudokuToSolve(solvedSudoku, mat);

  bool quit = false;
  while (!quit && !isSolved(mat)) {
    char c = '\0';
    int col = 0, row = 0, newNum = 0;
    cout << endl << endl;
    stampaSudoku(mat);
    cout << endl << endl;
    menu();
    cin >> c;
    switch (c) {
    case 'i':
      cout << "(col row newNum):";
      cin >> col >> row >> newNum;
      if (mat[row][col] == 0 && canInsert(newNum, mat, row, col)) {
        int solved[9][9] = {0};
        for(int i = 0; i < 9; i++){
          for(int j = 0; j < 9; j++){
            solved[i][j] = mat[i][j];
          }
        }
        solved[row][col] = newNum;
        if(!solveSudoku(solved)){
          cout << "cannot insert that number retry" << endl;
        }else{
          mat[row][col] = newNum;
        }
      } else {
        cout << "cannot insert that number retry" << endl;
      }
      break;
    case 'q':
      cout << "goodbye" << endl;
      quit = true;
      break;
    default:
      cout << "character not codified retry" << endl;
      break;
    }
  }

  if (isSolved(mat)) {
    cout << endl << endl;
    cout << "sudoku solved" << endl;
    cout << "#######################" << endl;
    cout << "#######################" << endl;
    stampaSudoku(mat);
    cout << "#######################" << endl;
    cout << "#######################" << endl;
    cout << endl << endl;
  }

  return 0;
}

void menu() {
  cout << "(i: insert a new number, q: quit): ";
}
