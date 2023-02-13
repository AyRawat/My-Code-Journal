#include<bits/stdc++.h>
using namespace std;

//Brute Force approach
int solve(string str){
    int maxAns = INT_MIN;
    for(int i=0;i<str.size();i++){
        unordered_set<int> set;
        for(int j=i;j<str.size();j++){
            if(set.find(str[j]) != set.end()){
                 maxAns = max(maxAns, j - i);
                 break;
            }else{
                set.insert(str[j]);
            }
        }
    }
    return maxAns==INT_MIN ? str.length(): maxAns ;

}

//Optimized approach
int optimal(string str){
    int uMap[27] = {0};
    int l = 0 ;
    int r = 0;
    int maxAns = INT_MIN;
    int answer = 0;
    while(l<str.size() && r<str.size()){
        if(uMap[str[r] - 'a']==0){
          uMap[str[r] - 'a'] = 1;
           r++;
           answer = r - l +1;
        }else{
           uMap[str[l] - 'a'] = 0;
           l++;
        }
        maxAns = max(maxAns , answer);
    }
    return maxAns;
}
int main() {
  string str = "abcabcbb";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}