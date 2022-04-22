#include <bits/stdc++.h>
using namespace std;

  int majorityElement(vector<int>& nums) {
           if(nums.size()==0) return -1;
        if(nums.size()==1) return nums[0];
        int element;
        int count = 0;
        int numSize = nums.size();
        for(int i=0;i<numSize;i++){
            if(count == 0){
                element = nums[i];
                count = 1;
                continue;
            }
            if(nums[i]==element){
                 count++;
            }else{
                 count--;
            }
        }
        return element;
    }