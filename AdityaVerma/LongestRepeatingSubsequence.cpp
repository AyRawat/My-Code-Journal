/*
INPUT:- AABEBCDD
OUTPUT:- 3
Exp:- ABD is the longest repeating subseq.
Logic:- if we pass the same string in both the parameters of the LCS function
        with a restriction that i!=j, then we can get the second occurence of the 
        Longest Repeating.
*/
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

int LRS(string a, string b, int m, int n){
    int t[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
             t[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1] && i!=j){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return t[m][n];
}

int main(){
  string a="AABEBCDD";
  cout<<LRS(a,a,a.size(),a.size());
    return 0;
}