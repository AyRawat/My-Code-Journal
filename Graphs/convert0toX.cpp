#include<bits/stdc++.h>

using namespace std;
 
void dfs(int i, int j, vector<vector<char>> mat, int m,
    int n, vector<vector<int>> &visited, vector<int> row, vector<int> col){
  if(visited[i][j] != 1) {
    visited[i][j] = 1;
    for(int k=0;k<4;k++){
      int nRow = i + row[k];
      int nCol = j + col[k];
      if(nRow >=0&& nRow< m && nCol >= 0 && nCol <= n && visited[nRow][nCol] != 1 
          && mat[nRow][nCol] == '0'){
        dfs(nRow, nCol , mat, m,n,visited,row,col);
      }
    }
  }
}
vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        // code here
       vector<vector<int>> visited(m, vector<int>(n,0));
       vector<vector<char>> result(m, vector<char>(n,'y'));
       vector<int> row {-1,0,1,0};
       vector<int> col {0,-1,0,1};
       //If a 0 is encountered in the boundaries. Use DFS to find the other Zeroes that are connected to it.
       for(int i=0; i<m;i++){
         if(mat[0][i]== '0'&&visited[0][i]!=1) dfs(0,i,mat,m,n,visited,row,col);
         if(mat[i][0] == '0'&&visited[i][0]!=1)dfs(i,0,mat,m,n,visited,row,col);
       }
       for(int i=n-1; i>=0;i--){
         if(mat[i][n-1]== '0'&&visited[i][n-1]!=1) dfs(i,n-1,mat,m,n,visited,row,col);
         if(mat[n-1][i] == '0'&&visited[n-1][i]!=1)dfs(n-1,i,mat,m,n,visited,row,col);
       }

       for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
           if(mat[i][j]=='0' && visited[i][j]!=1){
            mat[i][j] = 'X';
           }else if(mat[i][j] == '0' && visited[i][j]==1){
             mat[i][j] = '0';
           }else{
             mat[i][j] = 'X';
           }
         }
       }
       return result;
    }

int main(){

  return 0;
}
