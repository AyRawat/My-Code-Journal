//  At max you can do k transactions
//  3D dp
#include<bits/stdc++.h>
using namespace std;


   int solve(int index, int cap, bool flag, vector<int> &price){
            if(index >= price.size() || cap ==0) return 0;
            int profit = 0;
            if(flag){
                profit = max(-price[index] + solve(index+1, cap,false,price),
                solve(index+1,cap,true,price));
            }else{
                profit = max(price[index] + solve(index+1,cap-1,true,price),
                solve(index+1, cap, false, price)
                );
            }
            return profit;
        }
        int maxProfit(vector<int>&price){
           int n = price.size();
           vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
         
           
           for(int i=n-1;i>=0;i--){
               for(int j=0;j<=1;j++){
                   for(int k = 1; k<=2; k++){
                       if(j==1){
                       dp[i][j][k] = max(-price[i] + dp[i+1][0][k] , dp[i+1][1][k]);
                      }else{
                       dp[i][j][k] = max(price[i] + dp[i+1][1][k-1] , dp[i+1][0][k]);
                      }
                       
                   }
               }
               
           }
           
           return dp[0][1][2];
        }

int main(){
  return 0;
}
