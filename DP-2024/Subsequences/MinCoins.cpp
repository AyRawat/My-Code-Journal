#include<bits/stdc++.h>

using namespace std;

int recc(int n, vector<int> &num, int target) {
    if(target == 0) return 0;
    if(n == 0){
      if ((target % num[0]) == 0 )return (target / num[0]);
      else return 1e9;
    }
    if(num[n] == target) return 1;

    int pick = INT_MAX;
    int notPick = recc(n-1,num, target);
    if (num[n] <= target) {
     pick = 1 + recc(n,num,target-num[n]);
    } 
      return min(pick, notPick);
}


int tab(vector<int> &num, int target ){
  int n = num.size();
  vector<int> dp(n, vector<int>(target+1, -1));
  for(int i=0; i<=target;i++){
     if(i%num[0] == 0) dp[0][i] = i%num[0];
     else dp[0][i] = 1e9;
  }

  for(int i=1;i<n;i++){
    for(int j=0;j<=target;j++){
   int pick = INT_MAX;
   int notPick = dp[i-1][j];
   if(num[i] <= j) pick = 1 + dp[i][j - num[i]];
   dp[i][j] = min(pick, notPick);
    }
  }
return dp[n-1][target] == 1e9? -1 : dp[n-1][target];
}
int main(){
  vector<int> nums = {2,1};
  int target = 11;
  int solution = recc(nums.size()-1,nums,target);
  cout<<solution;
  return 0;
}
