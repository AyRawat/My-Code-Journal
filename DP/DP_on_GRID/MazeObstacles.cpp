#include<bits/stdc++.h>
using namespace std;

//Tabulation approach
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
  int dp[n][m];
     for (int i = 0; i < n; i++) {
       for(int j=0;j<m;j++){
         if (mat[i][j] == -1) {
             dp[i][j] = 0;
         } else if (i == 0 && j == 0){
              dp[i][j] = 1;
         }else{
             int up = 0, left = 0;
             if(i>0) up = dp[i-1][j];
             if(j>0) left = dp[i][j-1];
             dp[i][j] = up + left;
         }
         
       }
     }
     return dp[n-1][m-1];
}
//Reccursive approach

int solve(int n, int m, vector<vector<int> > &mat) {
     if( n == 0 && m ==0) return 1;
    else if(mat[n][m] == -1) return 0;
    else if(n<0 || m<0) return 0;
    int up =0, left=0;
    if(n>0) up = solve(n-1,m,mat);
    if(m>0) left = solve(n,m-1,mat);

    return up + left; 
}
int main(){
    int ans = solve(n-1,m-1,mat);
    return 0;
}