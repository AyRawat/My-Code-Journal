#include<bits/stdc++.h>
using namespace std;

//Recursive Solution

int LIS(int index, vector<int>&nums, vector<int>&result){
    if(index>nums.size()-1) return result.size();

    if(result.size()==0 || nums[index] > result[result.size()-1]){
        vector<int> temp = result;
        result.push_back(nums[index]);
        return max(LIS(index+1,nums,result), LIS(index+1,nums,temp)); 
    }
        return LIS(index+1,nums,result);
    
}

//DP Solution
int LISDP(vector<int>&nums){
    vector<int> dp(nums.size()+1,1);

    for(int i=1;i<nums.size();i++){
        for(int j=0;j<=i;j++){
            if(nums[i]>nums[j] && dp[i]<=dp[j]){
                dp[i] = 1+dp[j];
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}


int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    vector<int> result;
    int longInc = LIS(0,nums,result);
    int dpanswer = LISDP(nums);
    cout<<dpanswer;
    return 0;
}