#include<bits/stdc++.h>
using namespace std;

//It can contain any characters, even special ones too
bool validAnagram(string & a, string &b , int m , int n){
    if(m!=n) return false;
    vector<int> charMap(257,0);
    for(int i=0;i<m;i++){
       charMap[(int)a[i]]++;
       charMap[(int)b[i]]--;
    }
    for(auto i: charMap){
        if(i > 0){return false;}
    }
    return true;
}


int main(){
    string str1 = "!!@#$";
    string str2 = "$#@-!";
   bool ans = validAnagram(str1, str2, str1.size(),str2.size());
   cout<<ans;
    return 0;
}