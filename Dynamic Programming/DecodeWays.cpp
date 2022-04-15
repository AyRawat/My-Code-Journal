/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

#include<bits/stdc++.h>
#include<libcharset.h>
using namespace std;


//Recursive 
int decode(int index, string s, int n){
    if(s[index]=='0') return 0;
    if(index>=n) return 1;
     
     int ways =0;
     ways =  decode(index+1,s,n);
     if(index+1 < n && ((s[index] == '1' && s[index+1] <='9') || (s[index]=='2' && s[index+1] <='7') ) )
           ways += decode(index+2,s,n);
    return ways;

}
//Memoized Solution
int dp[101];
int memoDp(int index, string s, int n){
     if(s[index]=='0') return 0;
    if(index>=n) return 1;
     if(dp[index]!=-1) return dp[index];
     int ways =0;
     ways =  decode(index+1,s,n);
     if(index+1 < n && ((s[index] == '1' && s[index+1] <='9') || (s[index]=='2' && s[index+1] <='6') ) )
           ways += decode(index+2,s,n);
    return dp[index] =  ways;
}
//My Own Recursive Solution -Very Poor Solution
//TLE
int decodeWays(int index, string s, vector<string> &code){
    //Base Condition
     //If Index reaches to the end, that means we found a way to decode.
    if(index >= s.size()) return 1;

    string previous = code.back();
    cout<<previous<<" "<<s[index]<<endl;
    if(previous.length() == 1){
    //Handling the 0 case
        if(s[index] == '0' && stoi(previous) <= 2){
            previous+=s[index];
            code[code.size()-1] = previous;
            return decodeWays(index+1,s,code);
        }
        else if(s[index] == '0' && stoi(previous) > 2){ 
            return 0;
        }
        //Handling the Decoding case
        if(stoi(previous) <= 2){
 
            previous+=s[index];
         if(stoi(previous) <= 26){
             vector<string> temp = code;
              string tmp;
               tmp.append(1,s[index]);
             temp.push_back(tmp);
             code[code.size()-1] =  previous;
           return decodeWays(index+1,s,code) + decodeWays(index+1,s,temp);
           }
        }            
    }else if(previous.length()!=1 && s[index]=='0'){return 0;}
        string tmp;
    tmp.append(1,s[index]);
         code.push_back(tmp);
  return decodeWays(index+1,s,code);
  
}

int main(){
    string s = "11106";
      //If it starts from 0, then there is no way to decode
    if(s[0] == '0'){
       return 0;
    }
    vector<string> code;
    //code.back() = s[0];
    string tmp;
    tmp.append(1,s[0]);
    code.push_back(tmp);
   // int answer = decodeWays(1,s,code);
      memset(dp,-1,sizeof(dp));
   //cout<<answer;
    return 0;
}