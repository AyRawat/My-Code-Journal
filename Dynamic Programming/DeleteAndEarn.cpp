#include<bits/stdc++.h>

using namespace std;

//Recursive Solution

 int solve(vector<int> &nums, int i){
        if(i > nums.size()) return 0;
        
        int currValue = nums[i];
        int currSum = nums[i];
        int index = i+1;
        
        while(index < nums.size() && nums[index] == currValue){
            currSum+=nums[index];
            index++;
        }
        
        while(index < nums.size() && nums[index] == currValue+1){
            index++;
        }
        
        return max(currSum + solve(nums,index) ,  solve(nums,i+1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        return solve(nums,0);
    }

//DP solution, similar to House Robber
   int dpSolution(vector<int> &nums){
        vector<int> count(10002);
        
        for(int i=0;i<nums.size();i++){
            count[nums[i]]+=nums[i];
        }
        vector<int> dp(10002);
        dp[1] = count[1];
        dp[2] = max(count[1] , count[2]);
        for(int i = 3;i<dp.size();i++){
           if(count[i]) dp[i] = max(dp[i-1], count[i]+dp[i-2]);
else dp[i] = dp[i-1];
        }
        return max(dp[10000] , dp[9999]);
    }
int main(){
  vector<int> nums= {2,3,4};
  int ans = solve(nums,0);
  cout<<ans<<endl;
    return 0;
}