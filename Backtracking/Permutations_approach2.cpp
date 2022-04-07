/*
Given an array nums of distinct integers,
 return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include<bits/stdc++.h>
using namespace std;

/* TC: O(n! * n)
   SC: O(1)
*/
void permutationsTwo(int index,vector<int> &arr, vector<vector<int> >&finalResult){
  if(index == arr.size()){
      finalResult.push_back(arr);
  }
  for(int i=index;i<arr.size();i++){
      swap(arr[index],arr[i]);
      permutationsTwo(index+1,arr,finalResult);
       swap(arr[i],arr[index]);
      
  }
}

int main(){
    vector<int> arr= {1,2,3};
    vector<vector<int>> finalResult;
    unordered_map<int,int> uMap;
    permutationsTwo(0,arr,finalResult);
    for(auto i:finalResult){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}