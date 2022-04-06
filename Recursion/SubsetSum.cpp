#include<bits/stdc++.h>
using namespace std;

void solve(int index, int sum, vector<int> &arr, vector<int> &result){
    if(index>=arr.size()){
    result.push_back(sum);   
    return;
}
 solve(index+1,sum+arr[index],arr,result);
 solve(index+1,sum,arr,result);
}

int main(){
   vector<int> arr = {3,1,2};
   vector<int> result;
   solve(0,0,arr,result);
   for(auto i: result){
       cout<<i<<" ";
   }
    return 0;
}