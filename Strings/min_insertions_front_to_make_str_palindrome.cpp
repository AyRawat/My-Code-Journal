#include<bits/stdc++.h>
using namespace std;


vector<int> lps_array(string s){
    vector<int> lps (s.size() , 0);
    int i=1;
    int j = 0;
    while(i<s.size()){
        if(s[i] == s[j]){
            lps[i++] = ++j; 
        }else{
            if(j!=0){
               j = lps[j-1];
            }else{
               lps[i++] = 0;
            }
        }
    }
    return lps;
}
int solve(string A) {
    string temp = A;
    reverse(temp.begin() ,temp.end());
    string pattern = A + "$" +temp;
    vector<int> lps = lps_array(pattern);
    for(auto i: lps) {cout<<i<<" ";}
    return  A.length() - lps.back();  
}

int main(){
    solve("cac");
    return 0;}