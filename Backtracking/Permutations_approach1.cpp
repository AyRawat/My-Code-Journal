/*
Given an array nums of distinct integers,
 return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include<bits/stdc++.h>
using namespace std;

/* TC: n! * n
   SC: O(n) + O(n)
*/
void permutations(unordered_map<int,int>uMap,vector<int> &arr,vector<int>&result, vector<vector<int> >&finalResult){
if(result.size() == arr.size()){
    finalResult.push_back(result);
    return;
}
for(int i=0;i<arr.size();i++){
    if(uMap[arr[i]]) continue;
    result.push_back(arr[i]);
    uMap[arr[i]]++;
    permutations(uMap,arr,result,finalResult);
    result.pop_back();
    uMap[arr[i]]--;
}
}

int main(){
    vector<int> arr= {1,2,3};
    vector<vector<int>> finalResult;
    unordered_map<int,int> uMap;
    vector<int> result;
    permutations(uMap,arr,result,finalResult);
    for(auto i:finalResult){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}