#include "sudokuChecker.h"

bool canInsert(int newNum, int mat[9][9], int row, int col) {
  for (int i = 0; i < 9; i++) {
    if (mat[i][col] == newNum || mat[row][i] == newNum) {
      return false;
    }
  }
  if (row < 3) {
    if (col < 3)
      return checkLittleMatrix(0, 0, mat, newNum);
    else if (col < 6)
      return checkLittleMatrix(0, 3, mat, newNum);
    else
      return checkLittleMatrix(0, 6, mat, newNum);
  } else if (row < 6) {
    if (col < 3)
      return checkLittleMatrix(3, 0, mat, newNum);
    else if (col < 6)
      return checkLittleMatrix(3, 3, mat, newNum);
    else
      return checkLittleMatrix(3, 6, mat, newNum);
  } else {
    if (col < 3)
      return checkLittleMatrix(6, 0, mat, newNum);
    else if (col < 6)
      return checkLittleMatrix(6, 3, mat, newNum);
    else
      return checkLittleMatrix(6, 6, mat, newNum);
  }
  return false;
}

bool checkLittleMatrix(int startRow, int startCol, int mat[9][9], int newNum) {
  for (int i = startRow; i < (3 + startRow); i++) {
    for (int j = startCol; j < (3 + startCol); j++) {
      if (mat[i][j] == newNum) {
        return false;
      }
    }
  }
  return true;
}

bool isSolved(int solvedSudoku[9][9], int mat[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (mat[i][j] != solvedSudoku[i][j]) {
        return false;
      }
    }
  }
  return true;
}
