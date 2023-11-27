#include "solver.h"
#include "sudokuChecker.h"

bool solveSudoku(int mat[9][9]){
  bool isEmpty = false;
  int i = 0, j = 0;
  while(i < 9 && !isEmpty){
    j = 0;
    while(j < 9 && !isEmpty){
      if(mat[i][j] == 0){
        isEmpty = true;
      }
      j++;
    }
    i++;
  }
  
  if(!isEmpty){
    return true;
  }

  for(int num = 1; num <= 9; num++){
    if(canInsert(num, mat, i, j)){
      mat[i][j] = num;
      
      if(solveSudoku(mat)){
        return true;
      }
      
      mat[i][j] = 0;
    }
  }
  
  return false;
}
