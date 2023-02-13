//A classic example of Prefix sum technique
/*
Given an array of n integers, 
find if any index exists such that the sum of elements to its right is equal to the sum of elements to its left. If yes print the index, 
otherwise print “No Equilibrium”.
Example 1:
Input: N = 5, array[] = {7,2,1,5,4} 
Output: 2
Explanation: Sum of elements to the left of index 2 is 7+2=9 
and to the right of index 2 is 5+4=9.
*/
#include<bits/stdc++.h>
using namespace std;

int equilibrium(vector<int> arr){
int leftSum = 0;
int totalSum = 0;
int equiPoint = -1;
for(int i=0;i<arr.size();i++){
    totalSum+=arr[i];
}
for(int i=0;i<arr.size();i++){
    totalSum-=arr[i];
    if(leftSum == totalSum){
        equiPoint = i;
        break;
    }
    leftSum+=arr[i];
}
return equiPoint;
}

int main(){
    vector<int> arr = {7,2,1,5,4};
    int ans = equilibrium(arr);
    if(ans == -1) {
        cout<<"No Equilibrium";
    }else{
        cout<<"Equilibrium at "<<ans;
    }
    return 0;
}
