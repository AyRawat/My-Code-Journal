#include<bits/stdc++.h>
using namespace std;


int triangle (int i, int j, int m ,int n, vector<vector<int>> &grid){
if(i==m) return 0;
int downRight =0;
int down =0;
if(i<m)  down = grid[i][j] + triangle(i+1,j,m,n,grid);
if(j<n) downRight = grid[i][j] + triangle(i+1,j+1,m,n,grid);

return min(down, downRight);
}

//Memoization

int triangleMemo(int i, int j, int m ,int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
if(i==m) return 0;
if(dp[i][j] !=-1) return dp[i][j];
int downRight =0;
int down =0;
if(i<m)  down = grid[i][j] + triangleMemo(i+1,j,m,n,grid,dp);
if(j<n) downRight = grid[i][j] + triangleMemo(i+1,j+1,m,n,grid,dp);

return dp[i][j] = min(down, downRight);
}

int main(){
  vector<vector<int>> grid = {{1},{2,3},{3,6,7},{8,9,6,10}};
  int m = grid.size();
  int n = grid[m-1].size();
  int answer = triangle(0,0,m,n,grid);
  vector<vector<int>> dp(m,vector<int>(n,-1));
  int answer_two = triangleMemo(0,0,m,n,grid,dp);
  cout<<"The value of answer "<<answer <<"Memoized Answer"<< answer_two;
  return 0;
}
