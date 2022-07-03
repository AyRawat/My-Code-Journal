//LEETCODE : 376
#include<bits/stdc++.h>
using namespace std;

int wiggle(vector<int> &nums){
int len = nums.size() ;
if(len == 1) return 1;

int prev_diff = nums[1] - nums[0];
int counter = (prev_diff != 0)? 2 : 1;

for(int i = 2; i<len;i++){
    int curr_diff =nums[i]-nums[i-1];
    if((curr_diff > 0 && prev_diff <= 0 ) || (curr_diff <0 && prev_diff >= 0) ){
      counter++;
     prev_diff  = curr_diff;
    }
}
return counter;
}


int main(){
   vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
   int ans = wiggle(nums);
   cout<<ans<<endl;
    return 0;
}