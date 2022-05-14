   #include<bits/stdc++.h>
using namespace std;

   
   bool isPalindrome(string s) {
        int i =0;
        int j = s.size()-1;
        while(i<j){
            if(isalpha(s[i]) && isalpha(s[j])){
                //char ch1 = s[i];
                //char ch2 = s[j];
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
            }else{
                if(!isalpha(s[i])){i++;}
                if(!isalpha(s[j])){j--;}
            }
        }
        return true;
    }
    int main(){
        return 0;
    }