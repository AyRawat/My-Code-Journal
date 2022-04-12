/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/
#include<bits/stdc++.h>
using namespace std;
int houseRobberDP(vector<int>&nums){
    int n = nums.size();
    vector<int> dp(n+1);
    dp[0]=nums[0];
    dp[1]=max(dp[0],nums[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    }
    return dp[n-1];
   
}

int houseRobber(int index, vector<int>&nums){
    if(index>nums.size()-1) return 0;
    return max(houseRobber(index+2,nums)+nums[index] , houseRobber(index+1, nums));
}
int main(){
    vector<int> nums = {200,3,140,20,10};
    int result = houseRobber(0,nums);
    //A simple intuition, you can either take the first house but yo
    //will have to leave the last one, or you can skip this first one and consider the last one.
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    if(n==2) return max(nums[0], nums[1]);
    vector<int> v1(nums.begin(), nums.end()-1);
    vector<int> v2(nums.begin()+1, nums.end());
    result = max(houseRobber(0,v1),houseRobber(0,v2));
    int dpResult = max(houseRobberDP(v1) , houseRobberDP(v2));
    cout<<dpResult;
    return 0;
}