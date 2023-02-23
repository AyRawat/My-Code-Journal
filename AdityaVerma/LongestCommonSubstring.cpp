#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int lcs(string x, string y, int m , int n, int count){
    if(m==0 || n==0){
        return 0;
    }
    if(x[m-1] == y[n-1]){
        count = lcs(x,y,m-1,n-1,count+1);
    }else{
        count =  max( lcs(x,y,m,n-1,0), lcs(x,y,m-1,n,0) );
    }
    return count;
}

int main(){
        string x = "abcdgh";
    string y = "abedfhr";
   cout<<lcs(x,y,x.size(),y.size(),0);
    return 0;
}