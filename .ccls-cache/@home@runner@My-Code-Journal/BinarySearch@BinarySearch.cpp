#include<bits/stdc++.h>
using namespace std;


int binarySearch(vector<int> & nums , int target , int start , int end){
  if(start > end) return -1;
  int mid = (start + end)/2;
  if(nums[mid] == target) return mid;
  if(nums[mid] < target){
    return binarySearch(nums, target,start, mid-1);
  }else if(nums[mid] > target){
    return binarySearch(nums, target, mid+1,end);
  }

  return -1;
}
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }

int main(){
  vector<int> test = {-1,0,3,5,9,12};
  int result = search(test, 9);
  cout<<"This is the result"<<result;
  return 0;
}