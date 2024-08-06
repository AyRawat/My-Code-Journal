//You can buy any number of times. But remember you cannot buy two times, wothout selling.
#include<bits/stdc++.h>
using namespace std;

//Reccursive Operation
    int solve(int index, bool flag, vector<int> &prices){
        if(index >= prices.size()) return 0;
        int profits = 0;
        if(flag){
            profits =  max(-prices[index] + solve(index+1,false,prices) ,
            solve(index+1,true,prices));
            
        }else{
            profits = max(prices[index] + solve(index+1,true,prices) ,
            solve(index+1,false,prices));
        }
        return profits;
    }
//DP Operation
//This might look confusing, but this is actually very simple. You just need to move in the reverse order.
//Like from the bottom of the array to upwards.
//Also dp here signifies, [index][flag]
//Hope that helps
int stockBuyAndSell(int n, vector<int> &prices){
vector<vector<long>> dp(n+1, vector<long>(2,0));
dp[n][0] = dp[n][1] = 0;
 for(int ind=n-1 ; ind>=0 ; ind--){
   for(int buy=0; buy<=1;buy++){
     if(buy){
      dp[ind][buy] = max(-prices[ind] + dp[ind+1][0] , dp[ind+1][1]);
     }else{
      dp[ind][buy] = max(prices[ind] + dp[ind+1][1] , dp[ind+1][0])
     }
   }
 }
}



int main(){
  return 0;
}
