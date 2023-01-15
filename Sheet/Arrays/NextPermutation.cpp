/*
next_permutation : find next lexicographically greater permutation
link: https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order
(i.e., sorted in ascending order).

*/

#include <bits/stdc++.h>
using namespace std;


/*
The Algorithm :
 Traverse from the reverse .
1. index1 = a[i] < a[i+1]
2. index2 = a[index2] > a[index1]  -->The First index from behind which is greater than index1.
3. Swap the Values
4. Reverse the Array
*/
void optimalSolution(vector<int> &nums)
{   
         int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
}

int main()
{
    vector<int> arr = {1,1,5};
    optimalSolution(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}