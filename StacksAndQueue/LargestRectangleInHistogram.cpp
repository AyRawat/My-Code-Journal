#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
    int largestRectangleAreaBrute(vector<int>& heights) {
    int n = heights.size();
 int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, heights[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
    }
//Optimal approach using next smaller element
  //for finding the left smaller element
vector<int> leftSmallerElement(vector<int> &nums){
    int n = nums.size();
    vector<int> leftSmallerIndexes(n);
    stack<int> st;
    for(int i=0;i<n;i++){
    while(!st.empty() && nums[st.top()] >= nums[i])
    {
                st.pop();
            }
    if(st.empty()){
       leftSmallerIndexes[i] = 0;
    }else{
          leftSmallerIndexes[i] = st.top()+1;
    }
         st.push(i);
    }
    return leftSmallerIndexes;
}

  //for finding the right smaller elements
  vector<int> rightSmallerElement(vector<int> &nums){
      int n = nums.size();
      vector<int> rightSmallerIndex(n);
      stack<int> st;
      for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
                }
       if(st.empty()){
           rightSmallerIndex[i] = n-1;
       }else{
           rightSmallerIndex[i] = st.top() - 1;
       }
            st.push(i);
      }
      return rightSmallerIndex;
  }

 //Main function to get the maxArea
 int maxAreaRectangle(vector<int> nums){
     vector<int> leftSmaller = leftSmallerElement(nums);
     vector<int> rightSmaller = rightSmallerElement(nums);
     for(auto i: leftSmaller){cout<<i<<" ";}
     cout<<endl;
     for(auto i: rightSmaller){cout<<i<<" ";}
     cout<<endl;
     int maxArea = 0;
     for(int i=0;i<nums.size();i++){
      maxArea = max(maxArea,(rightSmaller[i] - leftSmaller[i] + 1)*nums[i]);
     cout<<maxArea<<" ";
     }
     return maxArea;
 }
int main(){
    vector<int> heights = {0,9};
    int val = maxAreaRectangle(heights);
    cout<<val<<endl;
    return 0;
}