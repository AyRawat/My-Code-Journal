/*
Kadane’s Algorithm : Maximum Subarray Sum in an Array
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and return its sum and print the subarray.
link: https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
*/

#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int> &nums , vector<int> & subArr){
    int max_so_far = INT_MIN;
    int max_ending_here =0  ,start = 0,end;
    for(int i = 0; i<nums.size();i++){
        max_ending_here += nums[i];
        if(max_ending_here > max_so_far){
            subArr.clear();
            max_so_far = max_ending_here;
            subArr.push_back(start);
            subArr.push_back(i);
        }
        if(max_ending_here < 0){
            max_ending_here = 0;
            start = i+1;
        }
    }
    return max_so_far;
}


int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> results;
    cout<<kadane(arr, results)<<endl;
    for(auto i: results){
        cout<<i<<" ";
    }
    return 0;
}