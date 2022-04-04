/*
Link to the Problem:- https://leetcode.com/problems/combination-sum/
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

*/

#include<bits/stdc++.h>
using namespace std;

void combinationSum(int index, vector<int> &arr,vector<int> &result, vector<vector<int>> &finalResult, int target){
 if(index == arr.size()){
     if(target==0){
         finalResult.push_back(result);
     }
     return;
 }
 if(arr[index]<=target)
 {
 result.push_back(arr[index]);
 combinationSum(index,arr,result,finalResult,target-arr[index]);
 result.pop_back();
 }

 combinationSum(index+1,arr,result,finalResult,target);
}


int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<int> result;
    vector<vector<int>> finalResult;
    combinationSum(0,candidates,result,finalResult,target);
    for(auto i: finalResult){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}