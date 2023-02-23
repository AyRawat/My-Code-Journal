#include<iostream>
#include<vector>

using namespace std;

//Reccursive Solution
int knapSack(vector<int> wt, vector<int> value, int w, int n){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1] <= w){
        return value[n-1]+ max(knapSack(wt,value,w-wt[n-1],n-1),knapSack(wt,value,w,n-1));
    }else if(wt[n-1] > w){
        return knapSack(wt,value,w,n-1);
    }
    
}
//DP
int KS(vector<int> wt, vector<int>value, int w, int n){
    if(n==0||w==0){return 0;}
    int t[n+1][w+1] = {-1};
    //initialization
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<= j){
                t[i][j] = max( value[i-1] + t[i-1][j-wt[j-1]], t[i-1][j] );
            }else if(wt[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
}

int main(){
    return 0;
}