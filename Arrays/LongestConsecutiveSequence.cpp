/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums){
 unordered_set<int> hSet(nums.begin() ,nums.end());
     int res = 0;
    for(auto num : nums){
    if (!hSet.count(num - 1)) 
    {
      int currentNum = num;
      int currentStreak = 1;

      while (hSet.count(currentNum + 1)) {
        hSet.erase(currentNum);
        currentNum += 1;
        currentStreak += 1;
      }
    res = max(res, currentStreak);
    }
    }
    return res;
}
int longestConsecutive(vector < int > & nums) {
 unordered_set<int> hSet(nums.begin(), nums.end());

  int longestStreak = 0;

  for (int num: nums) {
    if (!hSet.count(num - 1)) {
      int currentNum = num+1;

      int currentStreak = 1;
      cout<<currentNum<<" "<<currentStreak<<endl;
      while (hSet.count(currentNum)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}
   

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    int res = longestConsecutive(nums);
    cout<<solve;
    return 0;
}









