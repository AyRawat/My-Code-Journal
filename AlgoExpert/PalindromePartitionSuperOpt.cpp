//Solution not working in AlgoExpert
#include<bits/stdc++.h>

using namespace std;
vector< vector<int> > t(1001, vector<int>(1001 , -1));

bool isPalindrome(string s, int i, int j){
    if(i>=j){
        return true;
    }
    while(i<j){
        if(s[i]!=s[j]){return false;}
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int main_ans = INT_MAX;
    int left = -1 ;
    int right = -1 ;
    for(int K=i;K<=j-1;K++){
        if(t[i][K]!=-1){
          left = t[i][K];
        }else{
          left = solve(s , i,K);
          t[i][K] = left;
        }
        if(t[K+1][j]!=-1){
            right = t[K+1][j]; 
        }else{
            right = solve(s , K+1, j);
            t[K+1][j] = right;
        }
       int temp_ans = left + right + 1;
       main_ans = min(temp_ans , main_ans);
    }
    return t[i][j] = main_ans;
}
int palindromePart(string s){
    int t[s.size()][s.size()];
    //Creating a 2D array to keep the count, until where the string is palindrome
    for(int i=0;i<=s
    .size()-1;i++){
        for(int j=i;j<=s.size();j++){
            if(isPalindrome(s,i,j)){
                t[i][j] = true;
            }else{
                t[i][j] = false;
            }
        }
    }
    vector<int> cuts = {int(INFINITY)};
    for(int i=0;i<=s.size();i++){
        if(t[0][i]){
            cuts[i] = 0;
        }else{
            for(int j=0;j<i;j++){
                if( t[j][i] && cuts[j - 1] + 1 < cuts[i] ){
                    cuts[i] = cuts[ j - 1 ] + 1;
                }
            }
        }
    }
}

int main(){
string test = "abcdefghijklmracecaronpqrstuvwxyz";
    cout<<solve(test,0,test.size()-1);
    return 0;
    return 0;
}