#include<bits/stdc++.h>

using namespace std;


int gridPaths(int i, int j, int n, int m, vector<vector<int>> &mat){
  if(i>=n || j>= m) return 0;
  if(mat[i][j] == -1) return 0;
  if(i == n-1 && j==m-1) return 1;

  return gridPaths(i+1,j,n,m,mat) + gridPaths(i,j+1,n,m,mat);
}

int mod = (int)(1e9 + 7);
int mazeObstacles(int n, int m, vector<vector<int>>& mat) {
    // Write your code here
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) {
                dp[i][j] = 0;
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = (up + left ) %mod;
            }
        }
    }
    return dp[m - 1][n - 1] ;
}
int main(){
  vector<vector<int>> mat = {{0,0,0},{0,-1,0},{0,0,0}};
  int answer = gridPaths(0,0,3,3,mat);
  cout<<"Total Number of Unique Paths:- "<<answer;
  return 0;
}
