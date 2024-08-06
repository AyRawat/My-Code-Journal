//https://leetcode.com/problems/binary-subarrays-with-sum/
#include<bits/stdc++.h>

using namespace std;


    int countSubarr(vector<int> &nums, int goal){
     if(goal < 0) return 0;
     int l = 0; 
     int r = 0;
     int count = 0;
     int sum = 0;
     while(r < nums.size()){
      sum += nums[r];
       while(sum > goal){
        sum -= nums[l];
        l++;
       }
       count += (r - l +1);
       r++;
     }
     return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int subArrWithGoal = countSubarr(nums, goal);
      int subArrWithGoalMinus = countSubarr(nums, goal - 1);

      return subArrWithGoal - subArrWithGoalMinus;
    }

int main(){
  return 0;
}
