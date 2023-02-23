#include<bits/stdc++.h>
#include<string>

using namespace std;
//int t[1001][1001];
vector<vector<int> > t( 1001 , vector<int> (1001, -1));
//To Check whether the given string is palindrome or not;
bool isPalindrome(string s, int i, int j){
   if(i==j){
       return true;
   }
   if(i>j){
       return true;
   }
   while(i<j){
       if(s[i]!=s[j]){
           return false;
       }
           i++;
           j--;
   }
   return true;
}

//Reccursive Solution
int palinPartition(string s, int i, int j){
    //even for a single alphabet in the string we need to partition it 0 times.
    if(i>=j){
        return 0;
    }
    if( isPalindrome(s,i,j) ){
        return 0;
    }
   int ans = INT_MAX;
    for(int K=i; K<=j-1 ;K++){
        int val = palinPartition(s, i, K) + palinPartition(s,K+1,j) + 1;
        ans = min(ans,val);

    }
    return ans;
}
//BottomUp Approach
int solve(string x, int i, int j)
{
if(i>=j){
	return 0;
}
	if(isPalindrome(x,i,j)){
		return 0;
	}
	if(t[i][j] != -1)
	{
		return t[i][j];
	}
	int main_ans=INT_MAX;
	for(int K=i;K<=j-1;K++)
	{
		int temp_ans = solve(x,i,K) + solve(x,K+1,j) + 1;
		main_ans =   min(temp_ans , main_ans);
	}
	
	return t[i][j]=main_ans;
}


int main(){
    
   // memset(t,-1,sizeof(t));
    string test = "abcdefghijklmracecaronpqrstuvwxyz";
    cout<<solve(test,0,test.size()-1);
    return 0;
}