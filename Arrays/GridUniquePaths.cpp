#include<bits/stdc++.h>
using namespace std;

//Recursive
int gridUniquePaths(int m, int n, int i , int j){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
      return gridUniquePaths(m,n,i+1,j) + gridUniquePaths(m,n,i,j+1);
}
//Memoized T.C: O(N X M) ; S.C: _O(N X M);
int gridUniquePaths(int m, int n, int i , int j , vector<vector<int>>&dp){
    if(i==m-1 && j==n-1) return  1;
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
      return dp[i][j] = gridUniquePaths(m,n,i+1,j,dp) + gridUniquePaths(m,n,i,j+1,dp);
}
//Super Optimal Solution
int uniquePaths(int m, int n){
    int N = m + n -2; //Total Directions
    int r  = m -1 ; //For moving right, or you can also get n-1 for moving bottom
    double res = 1;
    for(int i = 1 ;i <=r ; i++){
       res *= (N-r+i)/i;
    }
    return (int) res;
}
int main(){
    int m = 4;
    int n = 4;
    vector<vector<int>> dp(m, vector<int>(n,-1));
    int ans = gridUniquePaths(4,4,0,0,dp);
    cout<<ans<<endl;
    return 0;
}