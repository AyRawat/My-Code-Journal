/*
You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.

At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

An integer x - Record a new score of x.
"+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
"D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
"C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
Return the sum of all the scores on the record.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
*/
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

int baseBall(vector<string> &ops){
  stack<int> st;
  for(int i=0;i<ops.size();i++){
      if(ops[i]=="C"){
         st.pop();
      }else if(ops[i] == "D"){
          int val1 = st.top();
          st.push(val1*2);
      }else if(ops[i] == "+"){
          int val1 = st.top();
          st.pop();
          int val2 = st.top();
          st.push(val1);
          st.push(val1+val2);
      }else {
         st.push(stoi(ops[i]));
      }
  }
  int sum = 0;
  while(!st.empty()){
        sum+=st.top();
        st.pop();
  }
  
  return sum;
}

int main(){
vector<string> ops = {"5","-2","4","C","D","9","+","+"};
int ans = baseBall(ops);
cout<<ans;
    return 0;
}