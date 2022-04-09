/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> kFrequent(vector<int> &nums, int k){
    unordered_map<int,int> fMap;
    for(int i=0;i<nums.size();i++){
        fMap[nums[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto i : fMap){
        pair<int,int> ele_freq_pair;
        ele_freq_pair.first = i.second;
        ele_freq_pair.second = i.first;
        pq.push(ele_freq_pair);
    }
    vector<int> answer;
    while(k-- > 0){
        auto it = pq.top();
        pq.pop();
        answer.push_back(it.second);
    }
    return answer;
}

int main(){
    
    return 0;
}