#include<bits/stdc++.h>
using namespace std;

//T.C: O(2N) , S.C: O(N)
string reverseWords(string &s){
    int len = s.length();
    stack<string> st;
    for(int i=0;i<len;i++){
        string word;
        if(s[i]!=' '){
          while(i<len && s[i]!=' '){
              word+=s[i];
              i++;
          }
          st.push(word);
        }
    }
string answer = st.top();
st.pop();
while(!st.empty()){
    answer+=" "+st.top();
    st.pop();
}
return answer;
}

//T.C: O(N), S.c: O(1)
string reverseWords(string s) {
     int len =s.length();
    string answer="";
    for(int i=0;i<len;i++){
        string word="";
        if(s[i]!=' '){
            while(i<len && s[i]!=' '){
             word+=s[i];
             i++;
            }
           answer != " "?answer = word + " " + answer:answer = word;
        } 
    }
        //To remove the trailing whitespaces
     while(answer[answer.size()-1]==' '){
            answer.pop_back();
        }
    return answer; 

    }
