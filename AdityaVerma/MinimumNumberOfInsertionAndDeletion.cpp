#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>

//This works only in the case of Insertion and Deletion

using namespace std;

int lcs(string a, string b, int m, int n){
   int t[m+1][n+1];
   for(int i=0;i<=m;i++){
       for(int j=0;j<=n;j++){
           if(i==0 || j==0){
               t[i][j] = 0;
           }
       }
   }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           if(a[i-1] == b[j-1]){
               t[i][j] = 1 + t[i-1][j-1];
           }else{
               t[i][j] = max(t[i-1][j] , t[i][j-1]);
           }
       }
   }
   return t[m][n];
}


int main()
{

    return 0;
}