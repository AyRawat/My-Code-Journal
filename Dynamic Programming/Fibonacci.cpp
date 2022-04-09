#include<bits/stdc++.h>
using namespace std;

//Reccursive Brute Force Solution
int fib(int n){
        if(n<=1)return n;
       return fib(n-1)+fib(n-2);
}

//Optimized DP Solution
   int fibDp(int n) {
        if(n<=1)  return n;
        vector<int> dp(n+1,0);
        cout<<dp.size();
        dp[0]=0;
        dp[1]=1;
        int i = 2;
        while(i<=n){
            dp[i++] = dp[i-1]+dp[i-2];
        }       
        return dp[n];
    }

int main(){

    return 0;
}