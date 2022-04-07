/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
 both indicate a queen and an empty space, respectively.
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

*/
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>&board, int n){
int dupRow  = row;
int dupCol = col;

while(dupRow>=0 && dupCol>=0){
    if(board[dupRow][dupCol] == 'Q'){
        return false;
    }
    dupRow--;
    dupCol--;
}
dupRow = row;
dupCol = col;

while(dupCol>=0){
    if(board[dupRow][dupCol] == 'Q') return false;
    dupCol--;
}
dupRow = row;
dupCol = col;
while(dupRow < n && dupCol >=0){
    if(board[dupRow][dupCol] == 'Q') return false;
    dupRow++;
    dupCol--;
}
return true;
}

void nQueens(int col, vector<vector<string>> &result, vector<string>&board, int n){
//base condition
if(col>=n){
    result.push_back(board);
    return;
}
for(int row = 0; row<n;row++){
    if(isSafe(row,col,board,n)){
        board[row][col] = 'Q';
        nQueens(col+1,result,board,n);
        board[row][col]= '.';
    }
}
}

int main(){
    int n = 4;
    vector<string> board;
    string col(n,'.');
    for(int i =0; i<n;i++){
        board.push_back(col);
    }
    vector<vector<string> > result;
    nQueens(0,result,board,n);
    return 0;
}