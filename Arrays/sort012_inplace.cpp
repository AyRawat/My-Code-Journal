#include<bits/stdc++.h>
using namespace std;

//Dutch National Flag Algorithm
 void sortColors(vector<int>& nums) {
    int i=0;
    int j = nums.size()-1;
    int k = 0;
    
    while(k<=j){
        if(nums[k] == 0){
            swap(nums[i] , nums[k]);
            i++;
            k++;
        }else if(nums[k]==1){
            k++;
        }else if(nums[k] == 2){
            swap(nums[k] , nums[j]);
            j--;
        }
    }}

int main(){
vector<int> nums = {0,1,2,1,1,0,0,2,2};
 sortColors(nums);
 for(auto i: nums){cout<<i<<endl;}
    return 0;
}