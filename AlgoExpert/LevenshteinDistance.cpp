#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Reccursive SOlution
int reccLDistance(string a, string b, int m , int n){
    if(m==0&&n==0){
        return 0;
    }else if(m==0){
        return n;
    }else if(n==0){
        return m;
    }
 
    if(a[m-1]==b[n-1]){
       return  reccLDistance(a,b,m-1,n-1);
    }else{
      return  1 + min(reccLDistance(a,b,m-1,n-1) , min(reccLDistance(a,b,m-1,n),reccLDistance(a,b,m,n-1)));
    }
    
}

int lDistance(string a, string b, int m , int n)
{
     int t[m+1][n+1];
     int length=0;
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
                 t[i][j]=1 + t[i-1][j-1];
             }else{
                 t[i][j]=max(t[i-1][j] , t[i][j-1]);
             }
     }
}
  length=abs(n-m);
   length+= m - t[m][n];
   return length;
}

int main(){
    string a = "table";
    string b = "bal";
    cout<<reccLDistance(a,b,a.size(), b.size());
    return 0;
}