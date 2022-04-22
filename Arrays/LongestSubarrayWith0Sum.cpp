/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n 
is the size of the array A and returns the length of the largest subarray with 0 sum.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> & nums, int n){
    if(n <=1 ) return n;
    int length = 0;
     int sum = 0;
    unordered_map<int,int> uMap;
   for(int i=0 ;i< n;i++){
       sum+=nums[i];
       if(sum == 0) 
        {
           length =  max(length,i + 1);
        }
        else {
        if(uMap.find(sum)!=uMap.end())
        {
             length = max(length, i - uMap[sum]);      
        }else{
           uMap[sum] = i;
        }
        }
   }
   return length;
}

int main(){
    vector<int> nums = {15,-2,2,-8,1,7,10,23};
    int res = solve(nums, nums.size());
    cout<< res;
    return 0;
}