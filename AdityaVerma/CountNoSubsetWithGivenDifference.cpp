#include<iostream>
#include<vector>

using namespace std;

int countSumOfSubset(vector<int> arr, int sum , int n){
    int t[n+1][sum+1];
    //Initialization
    for(int i=0;i<=n;i++){
        for (int j=0;j<=sum;j++){
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
        if(arr[i-1] <= j){
            t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
        }else{
            t[i][j] = t[i-1][j];
        }
    }
}
return t[n][sum];
}

int countNoSubsetWithDiff(vector<int> arr, int diff, int n){
    /*Formula : 
    (i) Sum(S1) + Sum(S2) = Sum(arr)
   (ii) Sum(S1) - Sum(S2) = diff
     ADDING both the equations
     i + ii
     2Sum(S1) + Sum(S2) - Sum(S2) = Sum(arr)+diff
     
     Conclusion: Sum(S1) = (Sum(arr) + diff)/2 
        
    */
   int sum =0;
   for(auto& num:arr){
       sum+=num;
   }
   int target = (sum - diff)/2;

   return countSumOfSubset(arr,target,n);
}

int main(){

    return 0;
}