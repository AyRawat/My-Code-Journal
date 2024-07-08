#include<bits/stdc++.h>
using namespace std;

//Brute Force approach
int solve(string str){
    int maxAns = INT_MIN;
    for(int i=0;i<str.size();i++){
        unordered_set<int> set;
        for(int j=i;j<str.size();j++){
            if(set.find(str[j]) != set.end()){
                 maxAns = max(maxAns, j - i);
                 break;
            }else{
                set.insert(str[j]);
            }
        }
    }
    return maxAns==INT_MIN ? str.length(): maxAns ;

}

//Optimized approach

int longestSubstrDistinctChars (string S)
{
    // your code here
    vector<int> uMap(256,-1);
    int l=0;
    int r=0;
    int maxLen = 0;
    int len = 0;
    while( r < S.size()) {
      if(uMap[S[r]]!=-1){
          if(uMap[S[r]] >= l){
              l = uMap[S[r]] + 1;
          }
      }
      len = r - l + 1;
      maxLen = max(maxLen, len);
        uMap[S[r]] = r;
        r++;
    }
    return maxLen;
}


int main() {
  string str = "abcabcbb";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}
