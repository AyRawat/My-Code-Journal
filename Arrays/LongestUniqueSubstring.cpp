/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include<bits/stdc++.h>

using namespace std;
//Kadane's
  int lengthOfLongestSubstring(string input) {
  ///=  if(input.size()==0) return 0;
 	int uMap[246]={0};
    int l=0;
    int r = 0;
    int answer = 0;
    int finalAnswer = 0;
    while(l<input.size() && r<input.size()){    
        if(uMap[input[r]-'a'<0 ? input[r]-'a'* -1:input[r]-'a']==0)
        {
            uMap[input[r]-'a'<0 ? input[r]-'a'*-1:input[r]-'a']=1;
            answer = r - l +1;
            r++;
        }else{
            uMap[ input[l]-'a'<0 ? input[l]-'a'*-1: input[l]-'a'] = 0;
            l++;
        }
           finalAnswer = max(finalAnswer,answer);
    }
    return finalAnswer;
    }

  
//Super Optimized;
  int lengthOfLongestSubstringOpti(string input) {
    vector<int> uMap(256,-1);
    int l = 0;
    int r = 0;
    int len = 0;
    while(r<input.size()){
        if(uMap[input[r]]!=-1) l = max(uMap[input[r]] + 1 , l);
         uMap[input[r]] = r;
         len = max(len, r - l +1);
         r++;
    }
    return len;
    }
int main(){
    string test = "abcabc!bb";
    int uMap[27] = {0};
    int res = lengthOfLongestSubstringOpti(test);
    cout<<res<<endl;
    char c= '!';
    cout<<c-'a';
    return 0;
}