#include<bits/stdc++.h>
using namespace std;
int longestPalindromicSubstr(string &str1,string &str2, int m, int n, int count ){
 if(m==0 || n==0) return 0;
 if(str1[m-1] == str2[n-1]){
    count = 1 +  longestPalindromicSubstr(str1,str2,m-1,n-1,count+1);
 }else{
    count = max(longestPalindromicSubstr(str1,str2,m-1,n,0) , longestPalindromicSubstr(str1,str2,m,n-1,0));
 }
 return count;
}


int main(){
    string str = "aabbcd";
    string str2 = str;
    reverse(str2.begin() , str2.end());
    int ans = longestPalindromicSubstr(str,str2,str.size(),str.size(),0);
    cout<<ans;
    return 0;
}