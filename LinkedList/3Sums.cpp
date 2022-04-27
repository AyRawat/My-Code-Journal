#include<bits/stdc++.h>
using namespace std;


//Best Approach
   vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size()<=1) return {};
    
    //Sort the array for two pointer approach
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    for(int i=0;i<nums.size()-2;i++)
    {
    if(i==0 || ( i>0 && nums[i]!=nums[i-1])){
  int sum = 0 - nums[i];
     int front = i+1;
     int back = nums.size()-1;
     while(front < back){
         if(nums[front] + nums[back] == sum)
         {
              result.push_back({nums[i] , nums[front] , nums[back]});
             
            while(front < back  && nums[front] == nums[front+1])front++;
            while(front < back && nums[back] == nums[back-1])back--;
            front++;
            back--;
         }
         else if(nums[front] + nums[back] < sum){
             front++;
         }else{
              back--;
         }
     }
    }
    }
   
    return result;
    }

int main(){
    return 0;
}