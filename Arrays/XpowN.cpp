#include<bits/stdc++.h>
using namespace std;

double powF(double x, int n){
    double ans = 1.0;
    long long nn = n;
    if(nn<0) nn=-1*nn;
    while(nn>0){
        if(nn%2!=0){
            ans*=x;
            nn-=1;
        }else{
            x=x*x;
            nn/=2;
        }
    }
    if(n<0) ans = (double)(1.0) / (double)(ans);
    return ans;
}

int main(){
    return 0;
}