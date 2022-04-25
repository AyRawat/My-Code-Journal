#include<bits/stdc++.h>

using namespace std;

//1st approach , using frequency array
vector<int> repeatedNumber(const vector<int> &nums) {
   vector<int> result;
   vector<int> freq_array(nums.size(),0);
   for(int i: nums){
       freq_array[i]+=1;
   }
   for(int i=1;i<freq_array.size();i++){
       if( freq_array[i] == 2){
           result.push_back(freq_array[i]);
       }else if(freq_array[i] == 0 ){
           result.push_back(freq_array[i]);
       }
   }
    return result;
    }

//2nd Approach
/*
Sum of all elements from 1 to N:

S = N*(N+1)/2 ---- equation 1
And, Sum of squares of all elements from 1 to N:

P = N(N+1)(2N+1)/6. ----- equation 2
Similarly, find the sum of all elements of the array and sum of squares of all elements of the array respectively.

s1 = Sum of all elements of the array. —– equation 3
P1 = Sum of squares of all elements of the array. ——– equation 4
Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y).

Therefore,

(X-Y) = s – s1 = s’

Similarily,

X^2 – Y^2 = P – P1 = P’

or, (X + Y)(X – Y) = P’

or, (X + Y)*s’ = P’

or, X + Y = P’/s’

Great,

we have the two equations we needed:

(X – Y) = s’

(X + Y) = P’/s’
Now
       X + Y = P’/s’
     + X - Y = s’

    2X = s’ + P’/s’
    X = (s’ + P’/s’)/2      //Missing Number Formula


    X - Y = s'
    Y = s' - X;            // Repeating Number 

*/
vector<int> repeatedNumberOptimal(const vector<int> &nums) {
    long long int n = nums.size();
    long long int S = (n *(n+1) )/2;
    long long int P = ((n * (n+1) * (2 * n + 1) )) / 6;

    long long int missingNumber = 0, repeating = 0;

    for(int i = 0; i < n;i++){
        S -= (long long int) nums[i];
        P -= (long long int) nums[i] * (long long int) nums[i];
    }
    missingNumber = (S + (P/S) ) / 2;
    repeating = missingNumber - S;

    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);


    return ans;
    }

int main(){
    return 0;
}