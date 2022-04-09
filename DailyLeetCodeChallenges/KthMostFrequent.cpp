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