#include<bits/stdc++.h>
using namespace std;

void printSubseq(int index, vector<int> &arr,vector<int> &result, int n){
    if(index == n){
        for(auto it:result){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
   result.push_back(arr[index]);
   printSubseq(index+1, arr,result,n);
   result.pop_back();
   printSubseq(index+1,arr,result,n);
}

int main(){
     vector<int> arr= {1,2,3};
     vector<int> result;
     printSubseq(0,arr,result,arr.size());
    return 0;
}