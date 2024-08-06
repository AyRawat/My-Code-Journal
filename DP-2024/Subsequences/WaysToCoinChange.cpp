#include<bits/stdc++.h>

using namespace std;

long countWays(vector<int> &denominations, int n, int target){
 //Base
 if(target == 0) return 0;
 if(n == 0) {
   if(target % denominations[n] == 0) return 1; 
   else return 0;
 }

 long notPick = countWays(denominations, n-1, target);
 long pick = 0;
if(denominations[n] <= target){
  pick =  countWays(denominations, n, target-denominations[n]);
}

return pick + notPick;

}


int main(){
  vector<int> denominations = {1,2,3};
  int target = 4;
  long res = countWays(denominations, denominations.size()-1, target);
  cout<<res;
  return 0;
}
