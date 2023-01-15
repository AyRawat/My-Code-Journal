#include<bits/stdc++.h>
using namespace std;

int stockAndBuy(vector<int> &arr){
    int maxProfit = 0;
    int output = 0;
    int minV = INT_MAX;
    for(int i =0 ;i<arr.size();i++){
         minV = min(arr[i] , minV);
         maxProfit = max(maxProfit  , arr[i] - minV);
    }
    return maxProfit;
}


int main(){
    return 0;
}