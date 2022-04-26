/*
Given an integer array nums that may contain duplicates,
 return all possible subsets (the power set).

The solution set must not contain duplicate subsets.
 Return the solution in any order.

 Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/
#include<bits/stdc++.h>
using namespace std;
//BruteForceApproach
   void subset(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      subset(nums, index + 1, ds, res);
      ds.pop_back();
      subset(nums, index + 1, ds, res);
    }

void subset(int index, vector<int> &arr, vector<int>&result,vector<vector<int>> &finalResult){
        finalResult.push_back(result);

    for(int i=index;i<arr.size();i++){
        if(i!=index && arr[i]==arr[i-1]) continue;
    result.push_back(arr[i]);
    subset(i+1,arr,result,finalResult);
    result.pop_back();
    }
}

int main(){
    vector<vector<int>> finalResult;
    vector<int> result;
    vector<int> arr = {1,1};
    sort(arr.begin(), arr.end());
    subset(0,arr,result,finalResult);
    for(auto i: finalResult){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}