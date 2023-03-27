#include <iostream>
#include <stack>
#include <string>

using namespace std;

int findLongestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLength = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i); 
        } else {
            if(!st.empty()){
                st.pop();
            }
            //st.pop(); 
            if (st.empty()) {
                st.push(i); 
            } else {
                maxLength = max(maxLength, i - st.top()); 
            }
        }
    }
    return maxLength;
}

int main() {
    string s = "()(()))))";
    int maxLength = findLongestValidParentheses(s);
    cout << "Length of longest valid parentheses substring: " << maxLength << endl;
    return 0;
}