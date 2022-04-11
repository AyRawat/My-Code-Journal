/*

There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
n = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair
and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs
then 1 stair.
Way 5: Climb 1 stair, then 1 stair and
then 2 stairs.
Example 2:

Input:
n = 10
Output: 89 
Explanation: 
There are 89 ways to reach the 10th stair.
*/
#include<bits/stdc++.h>
using namespace std;

//Reccursive
int countWaysReccursive(int n){
       if(n<=2)return n;
       return countWays(n-1) + countWays(n-2);
}

//Dp Optimised
      int countWays(int n)
    {
        // your code here
        if(n<=2)return n;
         vector<long int> dp(n+1,0);
         int mod = 1000000007;
         dp[0]=1;
         dp[1]=1;
         dp[2]=2;
        int i=3;
        while(i<=n){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
            i++;
        }
        return dp[n];
    }
//DP+Space optimized
     int countWays(int n)
    {
        // your code here
        if(n<=2)return n;
         int mod = 1000000007;
            // your code here
        int prev = 1 , prev2 = 1;
        for(int i = 2; i<=n; i++){
           int curr = (prev + prev2)%mod;
           prev2 = prev;
           prev = curr;
        }
        return prev;
    }


int main(){
   long int num = countWays(84);
   cout<<num;
    return 0;
}