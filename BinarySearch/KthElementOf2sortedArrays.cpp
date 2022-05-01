#include<bits/stdc++.h>
using namespace std;


int kthElement(vector<int> &nums1, vector<int> &nums2 , int k){
    if(nums2.size()<nums1.size()) return kthElement(nums2, nums1,k);
    int n1 = nums1.size();
    int n2 = nums2.size();
    int lo = max(0, k-n2);
    int hi = min(k,n1);
    while(lo<=hi){
        int cut1 = (lo+hi)/2;
        int cut2 = k-cut1;
        int l1 = cut1==0?INT_MIN: nums1[cut1-1];
        int l2 = cut2==0?INT_MIN: nums2[cut2-1];
        int r1 = cut1==n1?INT_MAX:nums1[cut1];
        int r2 = cut2==n2?INT_MAX:nums2[cut2];

        if(l1<=r2 && l2<= r1){
            return max(l1,l2);
        }else if(l1>r2){
            hi = cut1-1;
        }else{
            lo = cut1+1;
        }
    }
    return -1;
}

int main(){

    return 0;
}