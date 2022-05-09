#include<bits/stdc++.h>
using namespace std;
    int romanToInt(string s) {
        unordered_map<char,int> uMap={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
        int res = uMap[s.back()];
        for(int i=0;i<s.size()-1;i++){
            if(uMap[s[i]]<uMap[s[i+1]]) res-=uMap[s[i]];
            else
                res+=uMap[s[i]];
        }
        return res;
    }


int main(){
    return 0;
}