#include<bits/stdc++.h>
using namespace std;


 vector<int> lps_vector(string needle){
     int n = needle.size();
    vector<int> lps(n,0);
    for(int i=1, j =0;i<n;){
    if(needle[i]==needle[j]){
      lps[i++]=++j;
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

    bool checkSubstr(string haystack ,string needle){
    if(haystack.length()==0 && needle.length()==0 || needle.length()==0) return 0;
    if(haystack.length() == 0 ) return -1;
    int n = needle.size();
    int m = haystack.size();
    vector<int> lps = lps_vector(needle);
    for(int i=0, j=0;i<m;){
        if(haystack[i]==needle[j]){
           i++;
           j++;
        }
        if(j == n){
            return true;
        }
        if(i < m && haystack[i]!=needle[j]){
           j ? j = lps[j-1] : i++;
        }
    }
    return false;
}
    int repeatedStringMatch(string a, string b) {
        if(a.size() == 0 || b.size() == 0 ) return -1;
        int ans = 1;
        string temp = a;
        while(a.size() < b.size()){
            a+=temp;
            ans++;
        }
        
        if(checkSubstr(a,b)) return ans;
        if(checkSubstr(a+temp,b)) return ans+1;
        return -1;
    }

int main(){
    string a = "a";
    string b = "aa";
   int ans = repeatedStringMatch(a , b);
   cout<<ans<<endl;
    return 0;
}