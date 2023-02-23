#include<iostream>
#include<bits\stdc++.h>
#include<string>

using namespace std;
//Length of LCS
int lcs(string x, string y, int m , int n)
{
    if(m==0||n==0){
       return 0;
    }
    if(x[m-1] == y[n-1])
    {
        return 1 + lcs(x,y,m-1,n-1);
    }else
    {
        return max(lcs(x,y,m-1,n), lcs(x,y,m,n-1) );
    }
}
//DP Solution
int lcsDP(string x, string y, int m, int n){
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
    if(x[i-1] == y[j-1])
    {
        t[i][j] = 1 + t[i-1][j-1];
    }else{
        t[i][j] =  max(t[i-1][j] , t[i][j-1]);
    }
       }
   }
   return t[m][n];
}


int main()
{
    string x = "abcdgh";
    string y = "abedfhr";
   cout<<lcsDP(x,y,x.size(),y.size());
   return 0;
}