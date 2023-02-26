#include<bits/stdc++.h>
using namespace std;

//Readable and Easy solution
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(n==0) return "";
    if(n == 1) return arr[0];
    string prefix = "";
    for(int i=0;i<arr[0].length();i++){
       char character = arr[0][i];
       for (int j = 0; j < n; j++) {
           if(arr[j][i] != character) return prefix;
       }
       prefix = prefix + character;
    }  
    return prefix;
}

//Lengthy approach
    string longestCommonPrefix(vector<string>& strs) {
     string res = "";
        if(strs.size()==0) return res;
        if(strs.size()==1) return strs[0];
        int lenOfLCP = 0;
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i] == strs[1][i]){
                lenOfLCP++;
            }else{break;}
        }
        if(lenOfLCP==0) return res;
        if(strs[0].compare(0, lenOfLCP, strs[1], 0, lenOfLCP) == 0){cout<<"Compare is working fine";}
        cout<<lenOfLCP<<endl;
        int index = 1;
        while(index < strs.size()-1){
            string x = strs[index];
            string y = strs[index+1];
            int len = 0;
            bool flag = true;
            int temp = lenOfLCP;
             while(flag!=false){
                 cout<<temp<<endl;
                 if(temp==0) return res;
                 if (x.compare(0, temp, y, 0, temp) == 0) {
                     flag = false;
                     break;
                 }else{
                     temp--;
                 }
             }
             lenOfLCP = temp;
             index++;
        }
        return res = strs[0].substr(0,lenOfLCP);
    }
    //A much better approach
       string longestCommonPrefix(vector<string>& strs){
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }

int main(){
    vector<string> strs = {"flower","flow",""};
    string ans = longestCommonPrefix(strs);
    cout<<ans;
    return 0;
}