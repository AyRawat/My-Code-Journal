#include<bits/stdc++.h>
using namespace std;

bool allSmall(string word){
    for(int i=0;i<word.size();i++){
       if(int(word[i])<97 || int(word[i]) > 122) return false;
    }
    return true;
}
bool allCapital(string word){
    for(int i=0;i<word.size();i++){
       if(int(word[i])<65 || int(word[i]) > 90) return false;
    }
    return true;
}

bool detectCapitalUse(string word){
    string firstChar;
     firstChar += word[0];
  bool firstCharCapital = allCapital(firstChar); 
  if(firstCharCapital){
    //Case 1
    if(allCapital(word.substr(1)) || allSmall(word.substr(1))) return true;
     return false;
  }else{
    //Case 3
    if(!allSmall(word.substr(1))) return  false;
  }
  return true;
}

int main(){
    cout<<detectCapitalUse("GooglE");
    return 0;
}