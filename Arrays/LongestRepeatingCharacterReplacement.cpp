
/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/
#include<bits/stdc++.h>
using namespace std;

  int characterReplacement(string s, int k) {
        int result = INT_MIN;
        int start = 0;
        int end = 0;
        int globalMax = INT_MIN;
        vector<int> count(26,0);
        for(; end<s.size();end++){
            count[s[end]-'A']++;
            globalMax = max(globalMax, count[s[end]-'A']);
            if(((end-start)+1) - globalMax > k){
                result = max( result , (end-start) );
                count[s[start]-'A']-=1;
                start+=1;
            }
        }
        return max(result, end-start);
    }
int main(){
   string s = "AABABBA";
   int k = 1;
   int ans = characterReplacement(s,k);
   cout<<ans;
    return 0;
}