#include<bits/stdc++.h>
using namespace std;

//Recursive solution
int jumpGame(int index, vector<int>&arr){
    if(index >= arr.size()-1) return 0;
    int minValue =10001;
    for(int i = 1; i<=arr[index]; i++){
      minValue =min(minValue, 1 + jumpGame(i+index,arr) );
  
    }
    return minValue;
}
//memoized Solution
int jumpGame(int index, vector<int>&arr,vector<int> &dp){
    if(index >= arr.size()-1) return 0;
    if(dp[index]!=-1) return dp[index];
    int minValue =10001;
    for(int i = 1; i<=arr[index]; i++){
      minValue =min(minValue, 1 + jumpGame(i+index,arr,dp) );
    }
    return dp[index] = minValue;
}

int main(){
 vector<int> nums = {2,0,2,4,6,0,0,3};
 vector<int> dp(nums.size(), -1);
 int answer = jumpGame(0,nums,dp);
   cout<<answer;
    return 0;
}