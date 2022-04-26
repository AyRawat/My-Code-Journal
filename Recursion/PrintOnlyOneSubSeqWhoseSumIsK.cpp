#include<bits/stdc++.h>
using namespace std;

bool subseqSumK(int index, vector<int> &arr, vector<int> &result, int num, int sum){
    if(index == num){
        if(sum == 0){
        for(auto it:result){
            cout<<it<<" ";
        }
        cout<<endl;
        return true;
    }
    else {
        return false;
    }
    }
  
    result.push_back(arr[index]);
    if(subseqSumK(index+1,arr,result,num,sum-arr[index]) ) return true;
    result.pop_back();
    if(subseqSumK(index+1,arr,result,num,sum)) return true;
    return false;
}

int main(){
    vector<int> arr = {1,2,1};
    vector<int> result;
    subseqSumK(0,arr,result,arr.size(),2);
    return 0;
}