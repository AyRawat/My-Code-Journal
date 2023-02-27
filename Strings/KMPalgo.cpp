class Solution {
public:
int strStr(string haystack ,string needle){
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
            return i - j;
        }
        if(i < m && haystack[i]!=needle[j]){
           j ? j = lps[j-1] : i++;
        }
    }
    return -1;
}
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
};