/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char c){
  for(int i=0;i<9;i++){
      //Checking the same number in the row
      if(board[i][col]==c) return false;
      //Checking the same number in the col
      if(board[row][i]==c) return false;
      //Checkin if the number exist in the same box or not
      if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
  }
  return true;
}
bool sudokuSolver(vector<vector<char>> &board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
           if(board[i][j]=='.'){
             for(char c='1';c<='9';c++){
              board[i][j]=c;
              if(isSafe(board,i,j,c)==true){
                 if(sudokuSolver(board)==true){
                     return true;
                 }
              }else{ 
                 board[i][j]='.';
                }
             }
                return false;
           } 
        }
    }
}

int main(){

    return 0;
}