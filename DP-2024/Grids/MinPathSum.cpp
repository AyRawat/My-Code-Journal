#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int m, int n, int sum, vector<vector<int>> &grid) {
  if(i == m-1 && j == n-1) return sum;
  if(i>=m || j>= n) return 1e9;
  sum+= grid[i][j];
  return min(solve(i+1,j,m,n,sum,grid) , solve(i,j+1,m,n,sum,grid));
}




int main(){
  vector<vector<int>> grid = {{5,9,6},{11,5,2}};
  int answer = solve(0,0,2,0,3,grid);
  cout<<"The answer "<<answer;
  return 0;
}

