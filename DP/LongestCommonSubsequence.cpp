#include <bits/stdc++.h>

int solveLCS(string &str1, string &str2, int m, int n) {
  if(m ==0 && n==0) return str1[m] == str2[n]?1:0;
  if(m<0 || n<0) return 0;
  if(str1[m] == str2[n]){
    return 1 + solveLCS(str1,str2,m-1,n-1);
  }
  return max(solveLCS(str1,str2,m-1,n) , solveLCS(str1,str2,m,n-1));
}


int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int m = str1.size();
  int n = str2.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1,0));
  for (int i = 0; i <= m; i++) {
    for(int j = 0; j<=n ;j++){
      if(i==0 || j==0){
        dp[i][j] = 0;
      }
    }
  }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
      }
    }
  }
  return dp[m][n];
}