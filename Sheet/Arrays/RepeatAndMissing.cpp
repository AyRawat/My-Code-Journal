#include <bits/stdc++.h>
using namespace std;

// Approach 1 , using the frequency map
void solveApproachOne(vector<int> &nums)
{
    vector<int> arr(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        arr[nums[i]]++;
    }
    int rep, missing;
    for (int i = 1; i <= nums.size() + 1; i++)
    {
        if (arr[i] > 1)
        {
            rep = arr[i];
        }
        else if (arr[i] == 0)
        {
            missing = arr[i];
        }
    }
}

// Approach 2
/*
Let missing number be X and repeating Number be Y
 Sum of all numbers from 1 to N
  S = N * (N+1)/2
 Sum of Product of all no. from 1 to N
  P = N(N+1)(2N+1)/6
 Now, if we subtract the sum of all elements of array from sum
 of all elements from 1 to N, that should give us the value for
  (X – Y).
   
   X-Y = s - s1 = s`   
   Similarly,
   X^2 - Y^2 = P - P1 = P`
   (X-Y)(X+Y) = P`
   s`(X+Y) = P`    {X-Y = s` from above eq.}
   X+Y = P`/s`   

   Therefore, we have two equations now:
   X-Y = s`
   X+Y = P`/s`
*/
void missingRepeating(vector<int> & nums, long long int N){
    long long int missingNum = 0;
    long long int repeatingNum = 0;
    long long int S = (N*(N+1)) / 2;
    long long int P = (N*(N+1)*(2*N + 1)) / 6;
    for(int i=0;i<N;i++){
        S-=(long long int)nums[i];
        P-=(long long int)nums[i] * (long long int)nums[i];
    }  
    missingNum = (S + P/S)/2;
    repeatingNum = missingNum -  S;
}
int main()
{
    return 0;
}