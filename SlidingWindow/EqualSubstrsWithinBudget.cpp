//https://leetcode.com/problems/get-equal-substrings-within-budget/submissions/1270752362/?envType=daily-question&envId=2024-05-28
#include<bits/stdc++.h>

using namespace std;


int equalSubstrs(string s, string t, int maxCost){
 int n = s.size();
 int start = 0;
 int current_cost = 0;
 int max_length = 0;

 for(int end = 0; end< n ; ++end){
   current_cost += abs(s[end] - t[end]);

   while(current_cost > maxCost){
     current_cost -= abs(s[start] - t[start]);
     ++start;
   }
   max_length = max(max_length, end - start + 1);
 }
 return max_length;
}

int main(){
  string s = "jzmhzdq";
  string t = "rymuemg";
  int maxCost = 17;<

  int result = equalSubstrs("", s, t, maxCost, 0);

  cout<<"Result "<<result;
  return 0;
}
