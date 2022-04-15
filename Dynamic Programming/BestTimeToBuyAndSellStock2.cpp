/*
You are given an integer array prices where prices[i] is the price of a
 given stock on the ith day.

On each day, you may decide to buy and/or sell the stock.
 You can only hold at most one share of the stock at any time.
  However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/
#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
int solve(int index, vector<int> &prices, bool isBuy){
    if(index>= prices.size()) return 0;
    
     
     //When we are not holding any stock
     if(!isBuy){
         //You can either buy a stock or skip today's price
       return max(-prices[index]+solve(index+1,prices,true), solve(index+1,prices,false));
     }

         return max(prices[index] + solve(index+1,prices,false) , solve(index+1,prices,true) );
     

}
//Recursive + Memoized Approach
int solveMemoized(int index, vector<int> &prices, bool isBuy, vector<vector<int> > &dp){
    if(index>= prices.size()) return 0;
    if(dp[index][isBuy]!=-1) return dp[index][isBuy];
    
     
     //When we are not holding any stock
     if(!isBuy){
         //You can either buy a stock or skip today's price
       return dp[index][isBuy] = max(-prices[index]+solveMemoized(index+1,prices,true,dp), solveMemoized(index+1,prices,false,dp));
     }

         return dp[index][isBuy] = max(prices[index] + solveMemoized(index+1,prices,false,dp) , solveMemoized(index+1,prices,true,dp) );
     

}
int main(){
    vector<int> prices = {1,2};
    vector<vector<int> > dp(prices.size(),vector<int>(2,-1));
    int result = solveMemoized(0,prices,false,dp);
    cout<<result;

    return 0;
}