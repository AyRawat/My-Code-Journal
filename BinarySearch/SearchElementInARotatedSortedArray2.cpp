//Now we have the duplicates as well, so previous approach won't work here

#include<bits/stdc++.h>
using namespace std;

bool searchInRotatedSorted(vector<int> &nums, int target){
  int low = 0;
  int high = nums.size()-1;
  while(low <= high){
    int mid = (low + high) / 2;
    if(nums[mid] == target) return true;
    //If there are duplicates, then we need to trim down our search space
    if(nums[mid] == nums[low] && nums[mid] == nums[high]){
      low++;
      high--;
      continue;
    }
    //Check if the array is left sorted
    if(nums[low] <= nums[mid]){
       //Check if the array has the right sorted sequence in the left half for binary search
       if(nums[low] <= target && target <= nums[mid]){
           high = mid - 1;
       }else{
           low = mid + 1;
       }
    //Check if the array is right sorted   
    }else{
      //Check if the array has the right sorted sequence in the right half for binary search
      if(nums[mid] <= target && target <= nums[high]){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
  }
  return false;
}

int main(){
  vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
  bool result = searchInRotatedSorted(nums, 2);
  cout<<result;
  return 0;
}
