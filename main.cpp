/**
 *  @author whyKVD
 * */

#include <iostream>

using namespace std;

bool generateSudoku(int mat[9][9]);
void stampaSudoku(int mat[9][9]);
bool canInsert(int newNum, int mat[9][9], int row, int col);
void zero(int main[9][9]);

int main(int argc, char *argv[]) {

  int mat[9][9] = {0};

  srand(time(NULL));

  while(!generateSudoku(mat))
    zero(mat); 

  stampaSudoku(mat);

  return 0; 
}

bool generateSudoku(int mat[9][9]){
  cout << "generating sudoku" << endl;
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      int newNum = rand()%9+1;
      int flag = 0;
      while(!canInsert(newNum, mat, i, j) && flag < 9){
        newNum = rand()%9+1;
        flag++;
      }
      mat[i][j] = newNum;
    }
  }
  return true;
}

bool canInsert(int newNum, int mat[9][9], int row, int col){
  for(int i = 0; i < 9; i++){
    if(mat[i][col] == newNum || mat[row][i] == newNum){
      return false;
    }
  }
  for(int i = 0; i < 3; i++){
    if(mat[i][col] == newNum || mat[row][i] == newNum){
      return false;
    }
  }
  return true;
}

void stampaSudoku(int mat[9][9]){
  for(int i = 0; i < 9; i++){
    int j = 0;
    while(j < 3){
      cout << " " << mat[i][j];
      j++;
    }
    cout << " |";
    while(j < 6){
      cout << " " << mat[i][j];
      j++;
    }
    cout << " |";
    while(j < 9){
      cout << " " << mat[i][j];
      j++;
    }
    if((i+1)%3 == 0 && i != 8)
      cout << endl << " -----   -----   -----";
    cout << endl;
  }
}

void zero(int mat[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      mat[i][j] = 0;
    }
  }
}
