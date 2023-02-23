#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

vector<int> subsetSum(vector<int> arr, int sum, int n){
    vector<int> result;
    bool t[n+1][sum+1];
    //INITIALIZATION
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i=0){
                t[i][j]=false;
            }
            if(j=0){
                t[i][j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    for(int i=1;i<=sum/2;i++){
        if(t[n][i]==true){
            result.push_back(i);
        }
    }
    return result;
}

int minimumSubsetSumDifference(vector<int> arr, int n){
    if(n==0){
        return 0;
    }
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    vector<int> V = subsetSum(arr,sum,n);
    int minV  = INT_MAX;
    for(int i=0;i<V.size();i++){
       minV = min(minV, sum-(2*V[i]) );
    }
    return minV;
}
int main()
{
    vector<int> v= {1,2,7};
    cout<<minimumSubsetSumDifference(v,v.size());
    return 0;
}


