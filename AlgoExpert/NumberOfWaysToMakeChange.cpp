//DP
#include<iostream>
#include<vector>
using namespace std;

//Reccursive SOlution
int numberOfChanges(int target, vector<int> denom, int n)
{
   if(n==0){
       return 0;
   }  
   if(target==0){
       return 1;
   }
   if(denom[n-1]<=target){
       return  numberOfChanges(target-denom[n-1],denom,n)+numberOfChanges(target,denom,n-1);
   }else {
       return numberOfChanges(target,denom,n-1);
   }
}

//DP Solution
int numberOfChangesDP(int target, vector<int>& denoms, int n){
    int t[n+1][target+1];
    //INITIALIZATIOn
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++)
        {
            if(denoms[i-1]<=j){
                t[i][j] = t[i][j-denoms[i-1]] + t[i-1][j];
            }else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    return t[n][target];
}
int main(){
    vector<int> denom = {2,3,7};
    int n = 12;
    cout<<numberOfChangesDP(n,denom,denom.size());
    return 0;
}