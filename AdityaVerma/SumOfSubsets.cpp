#include<iostream>
#include<vector>

using namespace std;
//Reccursive Solution
bool isSubsetSum(int n, vector<int> arr, int sum){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1] <= sum){
        return isSubsetSum(n-1,arr,sum-arr[n-1]) || isSubsetSum(n-1,arr,sum);
    }else if(arr[n] > sum){
        return isSubsetSum(n-1,arr,sum);
    }
    
}

//DP Solution
bool isSubsetSumDP(int n, vector<int> arr, int sum){
    int t[n+1][sum+1];
    //INITIALIZATIOn
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] <= j)
            {
           t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else
            {
           t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int N = 6;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 30;
    cout<<isSubsetSumDP(N,arr,sum);
    return 0;
}