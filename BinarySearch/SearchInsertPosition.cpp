//https://leetcode.com/problems/search-insert-position/
//
#include<bists/stdc++.h>
using namespace std;

int searchInsertPosition(vector<int> nums, int target){
  return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main(){
  return 0;
}
