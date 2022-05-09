#include<bits/stdc++.h>
using namespace std;

string intToRoman(int num){
   int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string res = "";
    for(int i=0;i<13;i++){
        while(num>=val[i]){
             res.append(roman[i]);
             num-=val[i];
        }
    }
    return res;
}

int main(){
string ans = intToRoman(1994);
cout<<ans;
    return 0;
}