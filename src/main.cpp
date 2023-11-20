/**
 *  @author whyKVD
 * */

#include <iostream>
#include "sudokuGen.h"
#include "sudokuChecker.h"

using namespace std;

void menu();

int main(int argc, char *argv[]) {

  int solvedSudoku[9][9] = {0}, mat[9][9] = {0};

  srand(time(NULL));

  while (!generateSudoku(solvedSudoku)) {
    zero(solvedSudoku);
  }

  fillSudokuToSolve(solvedSudoku, mat);

  bool quit = false;
  while (!quit && !isSolved(solvedSudoku, mat)) {
    char c = '\0';
    int col = 0, row = 0, newNum = 0;
    stampaSudoku(mat);
    menu();
    cin >> c;
    switch (c) {
    case 'i':
      cout << "(col row newNum):";
      cin >> col >> row >> newNum;
      if (mat[row][col] == 0 && canInsert(newNum, mat, row, col) &&
          solvedSudoku[row][col] == newNum) {
        mat[row][col] = newNum;
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

  if (isSolved(solvedSudoku, mat)) {
    cout << "sudoku solved" << endl;
    cout << "#######################" << endl;
    cout << "#######################" << endl;
    stampaSudoku(mat);
    cout << "#######################" << endl;
    cout << "#######################" << endl;
  }

  return 0;
}

void menu() {
  cout << "(i: insert a new number, q: quit): ";
}
