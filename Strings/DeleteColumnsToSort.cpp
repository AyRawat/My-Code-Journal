#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> &strs){
    int result = 0;
     if(strs.size() == 1 || strs.size() == 0) return result;

     //Take First Instance out and loop
     string firstWord = strs[0];
     int i = 0;
   
     while(i<firstWord.length()){
     int maxValue = int(firstWord[i]);
        for(int j = 1;j<strs.size();j++){
         if(int(strs[j][i]) < maxValue ){
            result++;
            break;
         }else{
            maxValue = int(strs[j][i]);
         }
        }
        i++;
     }
     return result;
}


int main() {
   vector<string> strs = {"zyx","wvu","tsr"};
   cout<<minDeletionSize(strs);
    return 0;
}