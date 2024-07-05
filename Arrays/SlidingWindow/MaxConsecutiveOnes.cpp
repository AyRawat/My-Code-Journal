//https://leetcode.com/problems/max-consecutive-ones-iii/description/
//
//
#include<bits/stdc++.h>
using namespace std;

    int longestOnes(vector<int>& nums, int k) {
         int l = 0;
  int r = 0;
  int maxOnes = 0;
  int flips = k;
  int zCount = 0;
   while(r < nums.size()){
    if(nums[r] == 0) zCount++;

    if(zCount > k){
      if(nums[l] == 0 )zCount--;
      l++;
    }
    if(zCount <= k) maxOnes = max(maxOnes, r-l+1);
    r++;
  }
return maxOnes;
 
    }

int main(){

  vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
  int k = 2;
  int res = maxConsecutiveOnes(arr,k);
  cout<<res<<endl;
  return 0;
}

