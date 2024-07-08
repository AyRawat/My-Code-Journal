//https://leetcode.com/problems/fruit-into-baskets/
#include<bits/stdc++.h>
using namespace std;


    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int> uMap;
       int maxLen = 0;
       int l =0;
       int r = 0;
       int n = fruits.size();
       while(r < n){
         uMap[fruits[r]]++;
        if(uMap.size() > 2){
          while(uMap.size() > 2) {
            uMap[fruits[l]]--;
            if(uMap[fruits[l]] == 0) uMap.erase(fruits[l]);
            l++;
          }
        }else{
          maxLen = max(maxLen, r - l +1);
        }
         r++;
       } 
       return maxLen;
    }
