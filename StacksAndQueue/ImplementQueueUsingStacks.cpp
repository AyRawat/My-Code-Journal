#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s;
    stack<int> temp;
    MyQueue() {
        
        
    }
    
    void push(int x) {
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
       temp.push(x);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    }
    
    int pop() {
       int val = s.top();
        s.pop();
        return val;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};