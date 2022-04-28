#include<bits/stdc++.h>
using namespace std;

vector<int> removeDups(vector<int> &nums){
    if(nums.size() <=1) return nums;
    int i=0; int j =1;
    while(j<nums.size()){
     if(nums[i]!=nums[j]){
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return nums;
}
//When you are asked to return the first unique k element's index , or K
int removeDuplicates(vector<int>& nums) {
        if(nums.size() ==0) return 0;
    int i=0; int j =1;
    while(j<nums.size()){
     if(nums[i]!=nums[j]){
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i+1;  
    }
int main(){
  vector<int> nums = {1,1,2,2,2,2,3,3,4,4};
  removeDups(nums);
  for(auto i: nums){
      cout<<i<<" ";
  }
    return 0;
}