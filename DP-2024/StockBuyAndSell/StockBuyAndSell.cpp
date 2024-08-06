//You can buy and sell stocks only once. 

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &prices){
  
  int maxProfit =0;
  int min_price = prices[0];
  
  for(int i=0;i<prices.size();i++){
    int cost = prices[i] - mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, prices[i]);
  }
  return maxProfit;

}


int main(){
  return 0;
}
