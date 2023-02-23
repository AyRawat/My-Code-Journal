#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool LCS(string a, string b, int m, int n){
    int t[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1+t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    if(t[m][n] == a.length()){
        return true;
    }else{
        return false;
    }
}


int main(){
    string a ="AXY";
    string b = "ADXCPY";
    cout<<LCS(a,b,a.size(),b.size());
    return 0;
}