#include<bits/stdc++.h>

using namespace std;

int longestBitonicSubsequence(vector<int> &nums){
  int len = nums.size();
  vector<int> lis(len,1);
  vector<int> lds(len,1);
  for(int i=1;i<len;i++){
      for(int j=0;j<i;j++){
           if(nums[j]<nums[i] && lis[i]<=lis[j]){
               lis[i] = lis[j]+1;
           }
      }
  }
  for(int i = len-2;i>=0;i--){
      for(int j = len-1;j>i;j--){
          if(nums[j]<nums[i] && lds[i]<=lds[j] ){
              lds[i] = lds[j]+1;
          }
      }
  }
  //We are subtracting -1 here because the last number in LIS and LDS will be same, and we
  //do not want to count it twice. 5 in this case.
 // int maxV = lis[0]+lds[0]-1;
 int maxV = 0;
  for(int i=0;i<len;i++){
      maxV = max(maxV , lis[i]+lds[i]-1);
  }
  return maxV;
}

int main(){
    vector<int> nums = {1,2,5,3,2};
   int res =  longestBitonicSubsequence(nums);
    cout<<res<<endl;
    return 0;
}