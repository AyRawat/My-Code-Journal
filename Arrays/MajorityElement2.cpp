#include<bits/stdc++.h>
using namespace std;

vector<int> mooreVotingAlgo(vector<int> &nums){
    int N = nums.size();
    vector<int> result;
    int nums1 = -1;
    int nums2 = -1;
    int c1 = 0;
    int c2 = 0;
    for(int el : nums){
        if(el == nums1) {c1++;}
        else if(el == nums2) {c2++;}
        else if(c1==0){
            nums1 = el;
            c1=1;
        }else if(c2==0){
            nums2 = el;
            c2=1;
        }else{
            c1--;
            c2--;}
    }
    int validate_num1_count = 0;
    int validate_num2_count = 0;
    for(int i: nums){
          if(i == nums1){validate_num1_count++;}
          if(i == nums2){validate_num2_count++;}
    }
    if(validate_num1_count > N/3){result.push_back(nums1);}
    if(validate_num2_count > N/3 && nums1!=nums2){result.push_back(nums2);}
    return result;
}

int main(){
    return 0;
}