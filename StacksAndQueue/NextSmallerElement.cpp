#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
 stack<int> st;
 vector<int> result;
 st.push(A[0]);
 result.push_back(-1);
 for(int i =1 ; i<A.size();i++){
         if(A[i] > st.top()){
             result.push_back(st.top());
             st.push(A[i]);
         }else if(A[i]<=st.top()){
             while(!st.empty() && A[i]<=st.top()){
                 st.pop();
             }
             st.empty()?result.push_back(-1):result.push_back(st.top());
             st.push(A[i]);
         }
     
 }
return result;
}
int main(){
    vector<int> A = { 34, 35, 27, 42, 5, 28, 39, 20, 28 };
    vector<int> result = prevSmaller(A);
    for(int i : A){
        cout<<i<<" ";
    }
    return 0;
}