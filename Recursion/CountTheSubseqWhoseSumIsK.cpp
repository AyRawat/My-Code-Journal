#include<bits/stdc++.h>
using namespace std;
//1st Method
int subsetSum(int index,vector<int>&arr,vector<int> &subseq,int sum, int count){
    if(index==arr.size()){
        return count;
    }
     if(sum==0){
            count++;;
        }
    vector<int> temp = subseq;
    subseq.push_back(arr[index]);
    return subsetSum(index+1,arr,subseq,sum-arr[index],count) + subsetSum(index+1,arr,temp,sum,count);


}
//2nd Method
int countSubsetSum(int index,vector<int>&arr,vector<int> &subseq,int sum, int count){
    if(index==arr.size()){
        if(sum==0){
            return 1;
        }else{
            return 0;
        }

    }
    subseq.push_back(arr[index]);
    int l = subsetSum(index+1,arr,subseq,sum-arr[index],count) ;
    subseq.pop_back();
    int r = subsetSum(index+1,arr,subseq,sum,count);
    return l+r;
}

int main(){
    vector<int> arr= {1,2,1};
    vector<int> result;
    int count = subsetSum(0,arr,result,2,0);
    cout<<count;
    return 0;
}