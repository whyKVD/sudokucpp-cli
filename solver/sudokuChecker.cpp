#include "sudokuChecker.h"

bool canInsert(int newNum, int mat[9][9], int row, int col) {
  for (int i = 0; i < 9; i++) {
    if (mat[i][col] == newNum || mat[row][i] == newNum) {
      return false;
    }
  }
 
  int startRow = row - row % 3;
  int startCol = col - col % 3;
  
   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (mat[i + startRow][j + startCol] == newNum) {
        return false;
      }
    }
  }
  
  return true;
}

bool isSolved(int solvedSudoku[9][9], int mat[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (!canInsert(mat[i][j], mat, i, j) && mat[i][j] != 0) {
        return false;
      }
    }
  }
  return true;
}
