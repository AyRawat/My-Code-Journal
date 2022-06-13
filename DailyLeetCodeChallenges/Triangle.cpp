#include<bits/stdc++.h>
using namespace std;

//Recursive solution
int triangle(vector<vector<int> > &nums , int i, int j){
    
    //BASE COndition: if array is empty or index reaches at the end
    if(i>=nums.size()) return 0;
    //if there is only one element in the array;
    
   //if(i<nums.size() && j>= nums.size()) return nums[i][i];
   return  min(nums[i][j] + triangle(nums,i+1,j) ,nums[i][j]+triangle(nums, i+1,j+1) );
     
}
//Tabulation
int triangle(vector<vector<int> > &nums){
    int n = nums.size();
    vector<vector<int> > dp(nums.size(), vector<int> (nums.size() ,-1));

    for(int i=0; i<n;i++){
       dp[n-1][i] = nums[n-1][i];
    }
    for(int i = n-2;i>=0;i--){
        for(int j= i;j>=0;j--){
            dp[i][j] = min(dp[i+1][j] + nums[i][j] , dp[i+1][j+1]+nums[i][j]);
        }
    }
    return dp[0][0];
}

int main(){
    vector<vector<int> > arr = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int minV = triangle(arr,0,0);
    cout<<minV;
    return 0;

}