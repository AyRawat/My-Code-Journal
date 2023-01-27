/*
Problem Statement: Given an array of intervals,
 merge all the overlapping intervals and return an array of non-overlapping intervals.
*/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(vector<vector<int>> &arr){
    if(arr.size() <= 1) return arr;
    vector<vector<int>> result;
    sort(arr.begin() , arr.end());
    vector<int> curr = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i][0] <= curr[1]){
           curr[1] = max(arr[i][1] , curr[1]);
        }else{
           result.push_back(curr);
           curr= arr[i];
        }
    }
    return result;
}
int main(){
    return 0;
}