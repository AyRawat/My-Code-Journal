#include<bits/stdc++.h>
using namespace std;


int minSubsetSumDifference(vector<int>& arr, int n)
{

  //Sum of all the values
  int sum = 0;
  for(auto it: arr)  sum+= it;
	// Write your code here.
  vector<vector<bool>> dp(n, vector<bool>(sum+1, false));

  for (int i = 0; i < n; i++) {
   dp[i][0] = true;
  }
  if(arr[0] <= sum) dp[0][sum] = true;

  for (int i = 1; i < n; i++) {
   for (int j = 1; j <= sum; j++) {
   bool notTake = dp[i-1][j];
   bool take = false;
   if (arr[i] <= j) {
    take = dp[i-1][j-arr[i]];
   }
   dp[i][j] = take | notTake;
   }
  }
  int min_value = 1e9;
  for (int i = 0; i <= sum; i++) {
    if (dp[n-1][i] == true ) {
     min_value = min(min_value , abs(i - (sum - i) ));
   }
  }

  return min_value;
}

int main(){
  return 0;
}
