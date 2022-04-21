#include<bits/stdc++.h>
using namespace std;

//Recursive Solution
  int solve(vector<int> &coins, int amount, int n){
    if(n==0 || amount==0){
        return amount==0 ? 0 : INT_MAX-1;
    }

    if(coins[n-1] <= amount){
        return  min(1 + solve(coins, amount-coins[n-1],n) , solve(coins,  amount, n-1));
    }
    return solve(coins, amount, n-1);
}
    int coinChange(vector<int>& coins, int amount) {
        int answer= solve(coins,amount,coins.size());
     if(answer == INT_MAX-1) return -1;
        return answer;
    }
//DP Solution
int dpSolve(vector<int> &coins, int amount){
    int n = coins.size();
    int dp[n+1][amount+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=amount;j++){
        dp[0][j]  =INT_MAX-1;
    }
    //If you have only one coin
    for(int j=1;j<=amount;j++){
        if(j%coins[0]==0){
            dp[1][j] = j/coins[0];
        }else{
            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(coins[i-1] <= j){
                dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][amount] == INT_MAX-1){
        return -1;
    }else{
        return dp[n][amount];
    }
}
int main(){

    return 0;
}