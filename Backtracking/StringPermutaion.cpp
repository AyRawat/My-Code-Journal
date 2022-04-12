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
   SC: O(n)
*/
void permutationsString(unordered_map<char,int>uMap,string &s,string &result, vector<string>&finalResult){
if(result.size() == s.size()){
    finalResult.push_back(result);
    return;
}
for(int i=0;i<s.size();i++){
    if(uMap[s[i]]) continue;
    result.push_back(s[i]);
    uMap[s[i]]++;
    permutationsString(uMap,s,result,finalResult);
    result.pop_back();
    uMap[s[i]]--;
}
}
int main(){
    vector<int> arr= {1,2,3};
    vector<string> finalResult;
    unordered_map<char,int> uMap;
    string s = "SABG";
    string result;
    sort(s.begin(),s.end());
    permutationsString(uMap,s,result,finalResult);
    for(auto i:finalResult){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}