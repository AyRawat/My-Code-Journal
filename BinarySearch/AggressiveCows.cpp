#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &nums, int cows, int mid){
    int curr_cow_index = nums[0];
    int count = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i] - curr_cow_index >= mid){
            count++;
            curr_cow_index = nums[i];
        }
        if(count == cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &nums, int cows)
{
    sort(nums.begin(), nums.end());
    int low = nums[0];
    int high = nums[nums.size()-1] - low;
    int mid = low + (high-low)/2;
    int res = 0;
    while(low<=high){
        if(canPlace(nums,cows,mid)){
            res = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return res;
}


int main(){
    int t , n, c;
    cin>>t;
    vector<int> cows;
    int i;
    while(t--){
        cin>>n>>c; 
        while(n--){
            cin>>i;
            cows.push_back(i);
        }
        int result = aggressiveCows(cows,c);
        cout<<result;
    }
    return 0;
}