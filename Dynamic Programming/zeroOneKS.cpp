/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0
*/
#include<bits/stdc++.h>

using namespace std;
//Recursive Approach
   int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    if(W == 0|| n==0) return 0;
     if(wt[n]<W){
         return max(val[n]+knapSack(W-wt[n],wt,val,n-1) , knapSack(W,wt,val,n-1));
     }
     return knapSack(W,wt,val,n-1);
    }
//DP Approach
int ksDP(int W, int wt[], int val[], int n){
    if(W==0||n==0) return 0;

    int dp[n+1][W+1]={-1};

    for(int i = 0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){dp[i][j]=0;}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j =1 ; j<=W;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){

    return 0;
}