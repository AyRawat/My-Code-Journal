#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int sum, vector<int> &arr){
        if(sum == 0) return true;
        if(index==0) return (arr[0] == sum);
        if(index<0) return false;
        bool notTake = solve(index-1, sum, arr);
        bool take = false;
        if( sum >= arr[index])  take = solve(index-1, sum-arr[index], arr);
        
        return take + notTake;
}

bool isSubsetSum(vector<int> arr, int target){
  int n = arr.size();
  vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
  for(int i=0;i<n;i++) dp[i][0] = true;
  dp[0][arr[0]] = true;

  for(int i=1;i<n;i++){
    for(int j=1;j<=sum;j++){
      bool notTake = dp[i-1][j];
      bool take = false;
      if(j >= arr[i]) take = dp[i-1][j-arr[i]];
      dp[i][j] = notTake | take;
    }
  }
  return dp[n-1][target];

}

int main(){
  return 0;
}
