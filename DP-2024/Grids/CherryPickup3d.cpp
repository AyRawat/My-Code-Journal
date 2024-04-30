//Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

//Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

//If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

//Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

//Example:
//Input: ‘R’ = 3, ‘C’ = 4
 //      ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
//Output: 21

//Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

//Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

//Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.

#include<bits/stdc++.h>

using namespace std;

int maxChoc(int i,int j1, int j2, int m, int n, vector<vector<int>> & grid, vector<vector<vector<int>>> &dp){
  //Base condition
  if(j1<0 || j2< 0|| j1>=n || j2>= n) return -1e9;
  if(i == m-1){
if( j1 == j2) return grid[i][j1];
else return grid[i][j2] + grid[i][j1];
  }     
  if(dp[i][j1][j2] !=-1) return dp[i][j1][j2];
  int maxi = -1e9;
  int aliceShare = -1e9;
  int bobShare = -1e9; 
  for(int dj1 = -1; dj1 <=1; dj1++){
    for(int dj2 =-1; dj2<=1; dj2++){
     int value = 0;
      if(j1 == j2) value = grid[i][j1]; 
      else  value =grid[i][j1] + grid[i][j2];
      value += maxChoc(i+1,j1+dj1, j2+dj2,m,n,grid,dp);
      maxi = dp[i][j1][j2] = max(maxi, value);
    }
    }
return maxi  ;
}

int tabMaxChoc(intr, int c, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c, vector<int>(c,-1)));
   for(int j1=0;j1<c;j1++){
     for(int j2=0;j2<c;j2++){
       if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1];
       else dp[r-1][j1][j2] = grid[r-1][j2] + grid[r-1][j2];
     }
   }
   for(int i=r-2;i>=0;--i){
     for(int j1 =0; j1<c;j1++){
       for(int j2=0;j2<c;j2++){
         int value = 0;
      else  value =grid[i][j1] + grid[i][j2];
      if(j1+dj1>=0 && j1+dj1<c && j2+dj2>=0 && j2+dj2<c){
         value += dp[i+1][j1+dj1][j2+dj2];
      }else {
        value += -1e9;
      }
      maxi = max(maxi, value);
       }
     }
     dp[i][j1][j2] = maxi;
   }
   return dp[i][j1][j2];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c, vector<int>(c,-1)));
return maxChoc(0,0,c-1,r,c,grid,dp);
}


int main(){
  return 0;
}
