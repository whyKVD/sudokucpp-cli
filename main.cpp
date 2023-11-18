/**
 *  @author whyKVD
 * */

#include <iostream>

using namespace std;

bool generateSudoku(int mat[9][9]);
void stampaSudoku(int mat[9][9]);
bool canInsert(int newNum, int mat[9][9], int row, int col);
void zero(int main[9][9]);
bool checkLittleMatrix(int startRow, int startCol, int mat[9][9], int newNum);
void fillSudokuToSolve(int solvedSudoku[9][9], int mat[9][9]);
bool isSolved(int solvedSudoku[9][9], int mat[9][9]);
void menu();

int main(int argc, char *argv[]) {

  int solvedSudoku[9][9] = {0}, mat[9][9] = {0};

  srand(time(NULL));

  while(!generateSudoku(solvedSudoku)){
    zero(solvedSudoku);
  }

  fillSudokuToSolve(solvedSudoku,mat);
  
  bool quit = false;
  while(!quit && !isSolved(solvedSudoku,mat)){
    char c = '\0';
    int col = 0, row = 0, newNum = 0;
    stampaSudoku(mat);
    menu();
    cin >> c;
    switch(c){
      case 'i':
        cout << "(col row newNum):";
        cin >> col >> row >> newNum;
        if(mat[row][col] == 0 && canInsert(newNum, mat, row, col)){
          mat[row][col] = newNum;
        }else{
          cout << "cannot insert that number retry" << endl;
        }
        break;
      case 'm':
        cout << "(col row newNum):";
        cin >> col >> row >> newNum;
        if(canInsert(newNum, mat, row, col)){
          mat[row][col] = newNum;
        }else{
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

  if(isSolved(solvedSudoku,mat)){
    cout << "sudoku solved" << endl;
    cout << "#######################" << endl;
    cout << "#######################" << endl;
    stampaSudoku(mat);
    cout << "#######################" << endl;
    cout << "#######################" << endl;
  }

  return 0; 
}

void menu(){
  cout << "(i: insert a new number, m: modify a number, q: quit): ";
}

bool generateSudoku(int mat[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      int newNum = rand()%9+1;
      int flag = 0;
      while(!canInsert(newNum, mat, i, j) && flag < 100){
        newNum = rand()%9+1;
        flag++;
      }
      if(flag < 100 && canInsert(newNum, mat, i, j))
        mat[i][j] = newNum;
      else
        return false;
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
  if(row < 3){
    if(col < 3)
      return checkLittleMatrix(0,0,mat,newNum);
    else if(col < 6)
      return checkLittleMatrix(0,3,mat,newNum);
    else
      return checkLittleMatrix(0,6,mat,newNum);
  }else if(row < 6){
    if(col < 3)
      return checkLittleMatrix(3,0,mat,newNum);
    else if(col < 6)
      return checkLittleMatrix(3,3,mat,newNum);
    else
      return checkLittleMatrix(3,6,mat,newNum);
  }else{
    if(col < 3)
      return checkLittleMatrix(6,0,mat,newNum);
    else if(col < 6)
      return checkLittleMatrix(6,3,mat,newNum);
    else
      return checkLittleMatrix(6,6,mat,newNum);
  }
  return false;
}

bool checkLittleMatrix(int startRow, int startCol, int mat[9][9], int newNum){
  for(int i = startRow; i < (3 + startRow); i++){
    for(int j = startCol; j < (3 + startCol); j++){
      if(mat[i][j] == newNum){
        return false;
      }
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

void fillSudokuToSolve(int solvedSudoku[9][9], int mat[9][9]){
  int blankCell = rand()%10+30;
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(blankCell > 0){
        int isBlank = rand()%2;
        if(!isBlank){
          mat[i][j] = solvedSudoku[i][j];
          blankCell--;
        }
      }else{
        mat[i][j] = solvedSudoku[i][j];
      }
    }
  }
}

bool isSolved(int solvedSudoku[9][9], int mat[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(mat[i][j] != solvedSudoku[i][j]){
        return false;
      }
    }
  }
  return true;
}
