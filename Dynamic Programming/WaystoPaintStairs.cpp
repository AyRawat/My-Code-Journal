/*
Given n stairs and we have 2 colour yellow and green the task is that we have to paint given stairs by given colour with condition is that we cannot paints two yellow steps directly after each other.
Examples : 
 

Input : n = 1
Output : 2
A single stair can be colored either
as green or yellow.

Input : n = 3
Output : 5
*/
#include<bits/stdc++.h>
using namespace std;

//Reccursive Solution
int colorfulStairs(int num,char prevColor=' '){
 
   if(num==0) return 0;
   if(num == 1 && (prevColor==' ' || prevColor=='G') ){
       return 2;
       }else if(num==1 && prevColor=='Y'){
           return 1;
       } 
       int val = 0;
   //if(num==1)return 2;

   
   if(prevColor==' '|| prevColor == 'G'){
       val = colorfulStairs(num-1,'Y') + colorfulStairs(num-1,'G');
   }else if(prevColor=='Y'){
       val = colorfulStairs(num-1,'G');
   }
   return val;
}
//DP Solution
int dpSoln(int num){
    vector<int> dp(num+1,0);
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;
    int i = 3;
    int mod = 1000000007;
    while(i<=num){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
        i++;
    }
    return dp[num];
}
int main(){
    int answer = dpSoln(4);
    cout<<answer;
    return 0;
}
