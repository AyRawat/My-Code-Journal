   #include<bits/stdc++.h>
   using namespace std;

      bool isValid(string s) {
    stack<char> brackets;
    for(auto i:s){
        if(i=='{' || i=='['||i=='(')
        {
          brackets.push(i);
        }else{
            if(brackets.empty() 
            || (brackets.top()=='(' && i!=')')
            || (brackets.top()=='{' && i!='}')
            || ((brackets.top()=='[' && i!=']'))
            ) return false;
            brackets.pop();
        }
    }
    
    return brackets.empty();
    }