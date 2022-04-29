#include<bits/stdc++.h>
using namespace std;

class MyStack{
 private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    void push(int);
    int pop();

};

void MyStack :: push(int val){
    if(top<1000){
        arr[++top] = val;
    }
}
int MyStack :: pop(){
    if(top == -1) return -1;
    return arr[top--];
}
int main(){
    return 0 ;
}