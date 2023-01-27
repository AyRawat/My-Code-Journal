#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int> &nums){
    int s = nums[0];
    int f = nums[0];
    do{
        s = nums[s];
        f= nums[nums[f]];
    }while(s!=f);
    f= nums[0];
    while(s!=f){
        s = nums[s];
        f = nums[f];
    }
    return nums[s];
}

int main() {
    return 0;
}