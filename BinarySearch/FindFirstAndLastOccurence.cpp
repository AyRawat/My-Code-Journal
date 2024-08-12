#include<bits/stdc++.h>
using namespace std;


#include <vector>
using namespace std;

int lowerBound(int target, vector<int> &nums) {
    int lo = 0;
    int hi = nums.size() - 1;
    int ans = nums.size();

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int upperBound(int target, vector<int> &nums) {
    int lo = 0;
    int hi = nums.size() - 1;
    int ans = nums.size();

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (nums[mid] > target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1}; // Check if the vector is empty

    int lb = lowerBound(target, nums);

    // Ensure lb is within bounds and points to the target
    if (lb == nums.size() || nums[lb] != target) return {-1, -1};

    return {lb, upperBound(target, nums) - 1};
}


int main(){
  return 0;
}
