#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int solve(vector<int> denom, int sum, int n){
    int t[n+1][sum+1];
    //INITIALIZATION
    /*For any sum and 0 number of coins we theoretically need Infinite Number of coins*/
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
        {
            if(j==0){
                t[i][j] = 0;
            }
            if(i==0){
                t[i][j] = INT_MAX-1;
            }
        }
    }
    /*If only one coin is available then it can only be used if the sum == coin*/
    for(int j=1;j<=sum;j++)
    {
        if(j%denom[0] == 0){
             t[1][j]= j/denom[0];
        }else{
            t[1][j]=INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(denom[i-1]<=j){
               t[i][j] = min(t[i][j-denom[i-1]]+1 , t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
          
        }
    }
    if(t[n][sum]==INT_MAX-1){
return -1;
    }else{
      return t[n][sum];
    }
}


int main(){
    return 0;
}