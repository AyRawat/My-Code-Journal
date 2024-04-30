/*You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.

Down: (row+1,col)
Down left diagonal: (row+1,col-1)*/
//Down right diagonal: (row+1, col+1)


#include<bits/stdc++.h>
using namespace std;

int getMaxPathSumOfIndex(int i, int j, int m, int n, vector<vector<int>> &grid,vector<vector<int>> &dp){
  if(j<0 || j>=n) return -1e9;
  if(i==m-1) return grid[i][j];
  if(i>m) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int left = 0;
  int right = 0;
  int down = grid[i][j] + getMaxPathSumOfIndex(i+1,j,m,n,grid, dp);
  if(j-1>=0) left = grid[i][j] + getMaxPathSumOfIndex(i+1,j-1,m,n,grid,dp);
  if(j+1<n) right = grid[i][j] + getMaxPathSumOfIndex(i+1,j+1,m,n,grid,dp);
  return dp[i][j] = max({left,right,down});
}
int getMaxPathSum(int i, int m, int n, vector<vector<int>> &grid){
    int max_um = -1e9;
    vector<vector<int>> dp(m,vector<int>(n,-1));
    for(int j=0;j<n;j++){
      int maxPathSumOfCurrIndex = getMaxPathSumOfIndex(0,j,m,n,grid,dp);
      max_um = max(max_um , maxPathSumOfCurrIndex);
    }
return max_um;
}

//Tabulation Method
int tabGetMaxPathSum(vector<vector<int>> &grid){
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> dp(m,vector<int>(n,-1e9));
  //Fill out the first row
  for(int j=0;j<n;j++){
    dp[0][j] = grid[0][j];
  }
  for(int i=1;i<m;i++){
    for(int j=0;j<n;j++){
  int left = -1e9;
  int right = -1e9;
  int down = grid[i][j] + dp[i-1][j];
  if(j-1 >= 0) left = grid[i][j] + dp[i-1][j-1];
  if(j+1 < n) right = grid[i][j] + dp[i-1][j+1];
  dp[i][j] = max({down,left,right});
  cout<<"down - left - right - value --> "<<down <<" "<< left<<" "<<right<<" "<<dp[i][j]<<" "<<endl;
    }
  }
  int max_val = -1e9;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int j =0; j<n;j++){
    max_val = max(dp[m-1][j] , max_val);
  }
  return max_val;
}


int main(){
 //vector<vector<int>> grid ={{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
 vector<vector<int>> grid = {
 {-9999, -9888, -9777, -9666, -9555},
   {1, 10, 2, 4, 5},
   {-9999, -9888, -9777, -9666, -9555},
   {0, 0, 0, 0, 0},
   {-99, -98, -97, -96, -95}};
//  vector<vector<int>> grid ={{10,2,3},{3,7,2},{8,1,5}};
//  cout<<getMaxPathSum(0,grid.size(),grid[0].size(),grid);
  cout<<tabGetMaxPathSum(grid);
  return 0;
}
