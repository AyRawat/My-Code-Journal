/*
Given a string s, partition s such 
that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads
 the same backward as forward.
 Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/
#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void palindromePart(int index, string s, vector<string>&path, vector<vector<string>>&result){
    if(index == s.size()){
        result.push_back(path);
        return;
    }

    for(int i=index; i<s.size();
    ++i){
      if(isPalindrome(s,index,i)){
          path.push_back(s.substr(index, i-index+1));
          palindromePart(i+1,s,path,result);
          path.pop_back();
      }
    }
}

int main(){

    return 0;
}