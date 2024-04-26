#include<bits/stdc++.h>
using namespace std;

//Recursive approach
int totalUniquePaths(int i, int j, int m, int n, vector<vector<int>> & grid){
if(i>=m || j>= n) return 0;
if(i == m-1 && j == n-1) return 1;
return totalUniquePaths(i+1,j,m,n,grid) + totalUniquePaths(i,j+1,m,n,grid);
}

//Memoization

int totalUniquePathsMemo(int i, int j, int m, int n, vector<vector<int>> & grid, vector<vector<int>> & memo){
if(i>=m || j>= n) return 0;
if(i == m-1 && j == n-1) return 1;
if(memo[i][j] != -1) return memo[i][j];
return memo[i][j] = totalUniquePaths(i+1,j,m,n,grid) + totalUniquePaths(i,j+1,m,n,grid);
}

int main(){
  int m = 2; 
  int n = 2;
  vector<vector<int>> grid(m,vector<int>(n,1));
  int answer = totalUniquePaths(0,0,m,m,grid);
  vector<vector<int>> memo(m,vector<int>(n,-1));
  int memoAnswer = totalUniquePathsMemo(0,0,m,n,grid,memo);
  cout<<answer<<endl;
  return 0;
}
