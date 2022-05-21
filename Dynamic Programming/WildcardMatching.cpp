#include<bits/stdc++.h>
using namespace std;

//Recursive solution
bool wildCard(string &s, string &p , int i , int j){
    //Base condition
    if(i<0 && j< 0) return true;
    if(i<0 && j>=0) return false;
    //if s = "****" and p="" This should return true.
    if(j<0 && i>=0){
       for(int ii =0; ii<i;ii++){
          if(s[ii] != '*') return false;
          return true;
       }}
    //If characters are either same or there is a '?'
    if(s[i] == p[j] || s[i]== '?'){
       return wildCard(s,p,i-1,j-1);
    }else{
       if(s[i] == '*'){
           //In case of a star we will try to remove the elements which are equal to *
           return wildCard(s,p,i-1,j) || wildCard(s,p,i,j-1);
       }else{
           return false;
       }
    }

    
}


//The Memoized soltion will still take the auxillary stack space, therefore lets go for the Tabulation approach.
  bool isMatch(string s, string p) {
        if(p.length()==0)
            return (s.length()==0);
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[0][0]=1;
        for(int i=1;i<=p.length();i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=1;
            else
                break;
        }
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else if(p[j-1]==s[i-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[s.length()][p.length()];
      
    }
int main(){
string p = "";
string s = "****";
    bool ans = isMatch(s , p);
    bool ans2 = wildCard(s , p, s.size()-1, p.size()-1);
    cout<<ans<<" "<<ans2;
    return 0;
}