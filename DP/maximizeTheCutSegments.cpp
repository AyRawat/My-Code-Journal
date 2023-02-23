/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in
such a way that the cut length of a line segment each time is either x , y or z.
Here x, y, and z are integers. After performing all the cut operations,
your total number of cut segments must be maximum.
*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


//Reccursive Solution
  int solve(vector<int> cuts, int sum, int n ){
        if(sum==0||n==0){
            return 0;
        }
        if(cuts[n-1]<=sum){
            return max( 1+solve(cuts,sum-cuts[n-1],n) , solve(cuts,sum,n-1) );
        }else{
            return solve(cuts,sum,n-1);
        }
    }
//DP Solution
int solveDP(vector<int> cuts, int sum, int n){
    int t[n+1][sum+1];
    //INITITALIZATION
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j==0){
                t[i][j] = 0;
            }
            if(i==0){
                t[i][j] = INT_MIN;
            }
        }
    }
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(cuts[i-1] <= j){
                t[i][j] = max(1+t[i][j-cuts[i-1]] , t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
return t[n][sum];
}
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> cuts = {x,y,z};
        return solve(cuts, n, cuts.size() );
        
    }

int main(){
     int x = 5;
     int y = 5;
     int z = 2;
     int n=7;
     cout<<maximizeTheCuts(n,x,y,z);
    return 0;
}