/*
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.
*/
#include<bits/stdc++.h>
using namespace std;

 int partitionString(string s) {
      int n = s.size();
      if(n == 0 || n == 1) return s.size();
      int count = 1;
      unordered_map<char,int> uMap;
      int arr[27] = {-1};
      for(int i=0;i<n;i++){
        if(!uMap[s[i]]){
          uMap[s[i]]++;
        }else if(uMap[s[i]]){
          uMap.clear();
          count++;
          uMap[s[i]]++;
        }
      }
     return count;
    }