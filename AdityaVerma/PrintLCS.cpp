#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;
string printLCS(string x, string y, int m , int n){
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
            if(x[i-1] == y[j-1]){
                t[i][j] = 1+t[i-1][j-1];
            }else{
                t[i][j] = max( t[i-1][j] , t[i][j-1] );
            }
        }
    }
    int i = m;
    int j = n;
    string result="";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            result.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(t[i-1][j] > t[i][j-1]){
              i--;
            }else{
              j--;
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}


int main(){
     string x = "abcdgh";
    string y = "abedfhr";
   
    cout<< printLCS(x,y,x.size(),y.size());
    return 0;
}