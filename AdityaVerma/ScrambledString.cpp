#include<bits/stdc++.h>

using namespace std;


bool scrambled(string a, string b){
    //empty strings are scrambled
    if(a.length() == 0 && b.length()==0){
        return true;
    }
    //If both the strings are of different length then there is no way.
    if(a.length() != b.length()){

        return false;
    }
    // base condition for i
    if(a.length() <= 1){
        return false;
    }
     if(a.compare(b)==0){
        return true;
    }
    int len = a.length();
    bool flag = false;
    for(int i=1;i<=len-1;i++){
            //Case 1 With Swapping
        if( ( (scrambled(a.substr(0,i) , b.substr(len-i , i) ) ==true) && (scrambled(a.substr(i,len-i) , b.substr(0,len-i))==true) )
             ||//CASE 2 No Swapping
             ( (scrambled(a.substr(0,i) , b.substr(0,i) )==true)  && (scrambled(a.substr(i,len-i), b.substr(i,len-i))==true) )
             ){
                flag = true;
                break;
             }
    }
    return flag;


}


int main(){
    string x = "great";
    string y = "rgeat";
    cout<<scrambled(x,y);
    return 0;
}