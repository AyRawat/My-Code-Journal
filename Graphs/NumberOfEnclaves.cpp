#include<bits/stdc++.h>

using namespace std;

void dfs(
    int i, int j,
    int m, int n, 
    vector<vector<int> > & matrix,
    vector<vector<int> > & visited,
    vector<int> &rows,
    vector<int> &cols )
{
  if(visited[i][j]!=1){
    visited[i][j] = 1;
    for(int k=0;k<4;k++){
      int nR = i + rows[k];
      int nC = j + cols[k];
      if(nR >=0 && nR < m && nC >= 0 && nC <n && visited[nR][nC] != 1 && matrix[nR][nC] == 1){
        dfs(nR, nC, m,n, matrix,visited,rows,cols);
      }
    }
  }
}
int numberOfEnclaves(vector<vector<int>>& matrix){
int m = matrix.size();
int n = matrix[0].size();
vector<int> rows = {0,1,0,-1};
vector<int> cols = {-1,0,1,0};
int result = 0;
vector<vector<int> > visited(m, vector<int>(n,0));

  for (int col = 0; col < n; ++col) {
         cout << matrix[0][col] << " ";
         if(matrix[0][col] == 1) dfs(0,col,m,n,matrix,visited,rows,cols);
    }

    // Traverse the right boundary (excluding the first row)
    for (int row = 1; row < m; ++row) {
        cout << matrix[row][n - 1] << " ";
        if(matrix[row][n-1] == 1) dfs(row,n-1,m,n,matrix,visited,rows,cols);

    }

    // Traverse the bottom boundary (excluding the last column)
    for (int col = n - 2; col >= 0; --col) {
        cout << matrix[m - 1][col] << " ";
        if(matrix[m-1][col] == 1) dfs(m-1,col,m,n,matrix,visited,rows,cols);

    }

    // Traverse the left boundary (excluding the first and last rows)
    for (int row = m - 2; row > 0; --row) {
        cout << matrix[row][0] << " ";
        if(matrix[row][0] == 1) dfs(row,0,m,n,matrix,visited,rows,cols);
    }
    //Traverse the visited matrix and the main matrix now to get the answer;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(matrix[i][j] == 1 && visited[i][j]!=1){
          result++;
        }
      }
    }
    return result;
}
int main(){
  vector<vector<int>> matrix = {
    {0,0,0,0},
    {1,0,1,0},
    {0,1,1,0},
    {0,0,0,0}
  };
  int countOfEnclaves = numberOfEnclaves(matrix);
  cout<<"The number of Enclaves :"<<countOfEnclaves<<endl;
  return 0;
}
