/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 10^9 + 7.

Example 1:

Input:
N = 3
Output: 5
Explanation: 5 strings are (000,
001, 010, 100, 101).
Example 2:

Input:
N = 2
Output: 3
Explanation: 3 strings are
(00,01,10).
*/
#include<bits/stdc++.h>
using namespace std;

//Recursion
long long int countWays(int n, string s, char prev =' '){
if(n==0)return 1;
long long int count = 0;
if(prev==' '||prev=='0'){
    count = countWays(n-1,s+"0",'0') + countWays(n-1,s+"1",'1'); 
}else if(prev=='1'){
    count = countWays(n-1,s+"0",'0');
}
return count;
}
//DP Solution
long long int countWaysDPStyle(int n){
    vector<long long int> dp(n+1,0);
    dp[0]=1;
    dp[1]=2;
    int mod = 1e9+7;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return dp[n];
}
int main(){
    long long int answer = countWaysDPStyle(2);
    cout<<answer<<endl;
    return 0;
}