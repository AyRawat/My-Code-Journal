#include<iostream>
#include<vector>

using namespace std;
//This Reccursive call is not working but DP works fine
int sumOfSubset(vector<int> arr, int sum , int n,int s,int count){
    if(sum==0){
        count++;
    }
    if(n==0){
        if(sum==s){
            count++;
        }
        return count;
    }
    if(arr[n-1] < sum){
        return sumOfSubset(arr,sum,s+arr[n-1],n-1,count) + sumOfSubset(arr,sum,s,n-1,count);
    }else{
        return sumOfSubset(arr,sum,s,n-1,count);
    }
}
int sumOfSubsetDP(vector<int> arr, int sum , int n){
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }
for(int i=1;i<=n;i++){
    for(int j=1;j<=sum;j++){
       if(arr[i-1] <= j){
           t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
       }else{
           t[i][j] = t[i-1][j];
       }
    }
}
return t[n][sum];
}
int main()
{
     int N = 6;
    vector<int> arr = {2,3,5,6,8,10};
    int sum = 10;
    cout<<sumOfSubsetDP(arr,sum,arr.size());
    return 0;
}