//https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
//

#include<bits/stdc++.h>

using namespace std;

    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> uMap;
    int l =0;
    int r = 0;
    int maxLen = -1;
    
    while(r < s.size()){
        uMap[s[r]]++;
        if(uMap.size() > k){
            while(uMap.size() > k){
                uMap[s[l]]--;
                if(uMap[s[l]] == 0) uMap.erase(s[l]);
                l++;
            }
        }else if(uMap.size() == k){
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
    
    }
