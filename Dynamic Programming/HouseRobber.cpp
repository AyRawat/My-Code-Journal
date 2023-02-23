/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/
#include<bits/stdc++.h>
using namespace std;

//Recursive Approach-1
int houseRobber(int index, vector<int> &money, int totalSum){
    if(index > money.size()-1){
        return totalSum;
    }
    int maxValue = INT_MIN;
    for(int i=index;i<money.size();i++){
        maxValue = max(maxValue, houseRobber(i+2,money,totalSum+money[i]));
    }
    return maxValue;
}
//Recursive Approach-2
int houseRobber(int index, vector<int> &money){
    if(index > money.size()-1){
        return 0;
    }
    
    return max(money[index]+houseRobber(index+2,money) , houseRobber(index+1, money));
}
//DP

int houseRobberDP(vector<int> &money){
if(money.size() == 0) return 0;
if(money.size() == 1) return money[0];
vector<int> dp(money.size()+1,0);
dp[0] = money[0];
dp[1] = max(money[0] , money[1]);
for(int i=2;i<money.size();i++){
    dp[i] = max(dp[i-2]+money[i],dp[i-1]);
}

return dp[dp.size()-1];
}
int main(){
   vector<int> money={1,2,3,1};
   int result = houseRobber(0,money,0);
   //int dpRes = houseRobberDP(money);
   int recc_approach2 = houseRobber(0,money);
   cout<<result;
    return 0;
}
