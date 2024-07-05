//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#include<bits/stdc++.h>

using namespace std;
  int maxScore(vector<int>& cardPoints, int k) {
       
       int l =0;
       int r = cardPoints.size()-1;
       
       int lSum = 0;
       int rSum = 0;
      
      while(l<k){
        lSum += cardPoints[l++];
      }
      int maxSum = lSum;
      
     for(int i=0; i< k; i++){
      lSum -= cardPoints[k - 1 - i];
      rSum += cardPoints[cardPoints.size()- 1 - i];
      maxSum = max(maxSum, lSum + rSum);
     }
    return maxSum;
    }


int main(){
  return 0;
}
