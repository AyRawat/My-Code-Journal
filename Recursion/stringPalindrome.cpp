#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r){

if(l>s.size()/2){
    return true;
}
if(s[l]!=s[r])
   return false;
 
return isPalindrome(s, l+1,r-1);

}


int main(){
string x = "";
bool result = isPalindrome(x,0,x.size()-1);
cout<<result;
    return 0;
}