#include<bits/stdc++.h>
using namespace std;

   int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int result = INT_MIN;
        
        int max_prod = 1;
        int min_prod  = 1;
        
        for(int n: nums){
            if(n<0) swap(max_prod, min_prod);
            
            max_prod = max(max_prod * n, n);
            min_prod = min(min_prod * n, n);
            
            result = max(max_prod, result);
        }
        return result;
        
    }

int main(){
    vector<int> nums={2,3,-2,4};
      
    int result = maxProduct(nums);
    cout<<result;
    return 0;
}