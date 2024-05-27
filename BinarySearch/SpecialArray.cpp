//https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/submissions/1269156079/?envType=daily-question&envId=2024-05-27


#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ans = count(nums, mid);

            if (ans == mid) return mid;
            else if (ans > mid) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }
    int count(vector<int>& nums, int target) {
        int ans = 0;
        for (int num : nums) {
            if (num >= target) ans++;
        }
        return ans;
    }
};
