#include<bits/stdc++.h>
using namespace std;



bool wordBreak(int index,string s, unordered_set<string> &uSet,vector<int> &dp){
        
   if(index == s.size()) return true;
        
   if(dp[index]!=-1) return dp[index];
        
   for(int i=index; i<s.size();i++)
   {
       string val = s.substr(index,i-index+1);
       if(uSet.count(val)==1 and wordBreak(i+1,s,uSet,dp)){
           dp[index] = 1;
           return true;
       }
   }
   dp[index] = 0;
   return false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1);
        unordered_set<string> uSet(wordDict.begin(), wordDict.end());
        return wordBreak(0,s,uSet,dp);
    }

int main(){
    string s = "catsandog";
    string y = "applepenapple";
    vector<string> wordDict2 = {"apple","pen"};
    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    vector<int> dp(s.size(), -1);
    unordered_set<string> uSet(wordDict2.begin() ,wordDict2.end());
   
    cout<<wordBreak(0,y,uSet,dp);
    
    string s2 = "ayushrawat";
    vector<string> dict = {"ayush","rawat"};
    return 0;
}