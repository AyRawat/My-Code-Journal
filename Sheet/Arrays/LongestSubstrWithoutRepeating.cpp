/*
Given a String, find the length of longest substring without any repeating character.
*/

#include<bits/stdc++.h>
using namespace std;

int maxLen(string &s , vector<char> &fMap , int index, int len){
    if(s.length()<=0 ) return 0;
    if(s.length() == 1) return 1;
    if(index >= s.size()) return len;
    //For including the current char into the substring
    int len1 ,len2;
    if(fMap[s[index] - 'a']==0){
      fMap[s[index] - 'a']++;
      
    } 
    return len;
}

int main (){

    return 0;
}