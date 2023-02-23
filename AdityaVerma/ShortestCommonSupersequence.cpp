#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//for printing the Length of SCS.
  /*LOGIC: the Longest Sequence that is Common in both can be found out 
    using LCS technique. If we remove that from one of the string and
     merge it with the other string then the length will be equal to 
     the SCS*/
int printLenSCS(string a, string b, int m, int n){
    int t[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                t[i][j] = 0;
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
    int lenLCS = t[m][n];
    cout<<lenLCS<<endl;
    int ans = (m+n) - lenLCS;
    return ans;

}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout<< printLenSCS(a , b, a.size(),b.size());
 
 return 0;
    }