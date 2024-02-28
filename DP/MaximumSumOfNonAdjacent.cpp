#include <bits/stdc++.h>
//Reccursive
int solve(int index, vector<int> &nums) {
    if(index == 0) return nums[index];
    //if(index == 1) return max(nums[0] , nums[1]);
    if(index<0) return 0;

    int chosen = nums[index] + solve(index-2, nums);
    int notChosen = solve(index-1,nums);

    return max(chosen,notChosen);
}
//Tabulation

int solveDP(int n, vector<int> &nums) {
   vector<int> dp(n+1, 0);
   //if(nums.size() == 2) return max(nums[0] , nums[1]);
    dp[0] = nums[0];
   for (int i = 1; i < n; i++) {
       int chosen = INT_MIN;
       if(i>1){
        chosen = nums[i] + dp[i-2];
       } else {
       chosen = nums[i];
       }

      int notChosen = dp[i-1];
      dp[i] = max(chosen, notChosen);
   }
   return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solveDP(nums.size(), nums);
}