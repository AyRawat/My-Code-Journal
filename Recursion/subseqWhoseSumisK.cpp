#include<bits/stdc++.h>
using namespace std;

void subseqSumK(int index, vector<int> &arr, vector<int> &result, int num, int sum){
    if(index == num){
        if(sum == 0){
        for(auto it:result){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return;
    }
  
    result.push_back(arr[index]);
    subseqSumK(index+1,arr,result,num,sum-arr[index]);
    result.pop_back();
    subseqSumK(index+1,arr,result,num,sum);
}

int main(){
    vector<int> arr = {1,2,1};
    vector<int> result;
    subseqSumK(0,arr,result,arr.size(),2);
    return 0;
}