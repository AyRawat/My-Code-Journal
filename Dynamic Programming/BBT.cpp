/*
Given a height h, count and return the maximum number of balanced binary trees possible with height h. A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.
Examples : 
 

Input : h = 3
Output : 15

Input : h = 4
Output : 315
*/
#include<bits/stdc++.h>
using namespace std;

//Recursive SOlution
int countBBT(int h){
    if(h==0||h==1) return 1;

    return countBBT(h-1) * (2*countBBT(h-2)+countBBT(h-1));
}

//DP SOlution
  long long int countBT(int h) { 
        // code here
        vector<long long int> dp(h+1,0);
        int mod = 1e9+7;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=h;i++){
            dp[i] =(dp[i-1]*((2*dp[i-2])%mod+dp[i-1])%mod)%mod;
        }
        return dp[h];
    }
int main(){

    return 0;
}