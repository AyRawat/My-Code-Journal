/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
#include<bits/stdc++.h>
using namespace std;

//Recursion
int perfectSquare(int n){
    if(n==0) return 0;

    int minValue = INT_MAX;
    for(int i=1;i*i<=n;i++){
        minValue = min(minValue, perfectSquare(n-(i*i)));
    }
    minValue+=1;

    return minValue;
}

//DP Solution
int dpSOln(int n){
    vector<int> dp(n+1,0);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
         int minValue = INT_MAX;
        for(int j=1;j*j<=i;j++){
        minValue = min(minValue, dp[i-j*j]+1);
        }
        dp[i] = minValue;
    }
    return dp[n];
}
int main(){
    int x = perfectSquare(12);
    int y = dpSOln(12);
    cout<<y;
    return 0;
}