#include<iostream>
#include<vector>
using namespace std;
    
    bool subsetSum(int a[],int sum , int n){
        bool t[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    t[i][j] = false;
                }
                if(j==0){
                    t[i][j] = true;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(a[i-1]<=j){
                    t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool findPartition(int a[], int n)
    {

        // code here
  /*
  Checking whether it is possible or not;
     SumArr == Odd;
     Not Possible , because odd can't be divided by 2 Completely hence No partition
  Finding The Subset
     S1 + S2 = SumArr;
     Equal Sum Means :- S1 == S2;
     2S = SumArr;
     S = SumArr/2;


  */
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum%2!=0){
            return false;
        }else{
            return subsetSum(a,sum/2,n);
        }
    }
int main(){

    return 0;
}