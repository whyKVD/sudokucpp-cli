#include <iostream>
#include "sudokuGen.h"
#include "sudokuChecker.h"

using namespace std;

bool generateSudoku(int mat[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int newNum = rand() % 9 + 1;
      int flag = 0;
      while (!canInsert(newNum, mat, i, j) && flag < 70) {
        newNum = rand() % 9 + 1;
        flag++;
      }
      if (flag < 70 && canInsert(newNum, mat, i, j))
        mat[i][j] = newNum;
      else
        return false;
    }
  }
  return true;
}

void stampaSudoku(int mat[9][9]) {
  for (int i = 0; i < 9; i++) {
    int j = 0;
    while (j < 3) {
      cout << " " << mat[i][j];
      j++;
    }
    cout << " |";
    while (j < 6) {
      cout << " " << mat[i][j];
      j++;
    }
    cout << " |";
    while (j < 9) {
      cout << " " << mat[i][j];
      j++;
    }
    if ((i + 1) % 3 == 0 && i != 8)
      cout << endl << " -----   -----   -----";
    cout << endl;
  }
}

void fillSudokuToSolve(int solvedSudoku[9][9], int mat[9][9]) {
  int blankCell = rand() % 10;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (blankCell > 0) {
        int isBlank = rand() % 2;
        if (!isBlank) {
          mat[i][j] = solvedSudoku[i][j];
          blankCell--;
        }
      } else {
        mat[i][j] = solvedSudoku[i][j];
      }
    }
  }
}

void zero(int mat[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      mat[i][j] = 0;
    }
  }
}
