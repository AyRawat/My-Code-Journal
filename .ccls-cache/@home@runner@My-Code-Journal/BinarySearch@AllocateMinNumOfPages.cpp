#include<bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int> &A,int mid, int n){
       int pages = 0;
       int students = 1;
       for(int i=0;i<A.size();i++){
           if(A[i] > mid) return false;
           if(A[i]+pages > mid){
              students++;
              pages=A[i];
           }else{
                pages+=A[i];
           }
       }
       return students>n?false:true;
}

int books(vector<int> &A, int B) {
    if(B>A.size()) return -1;
    int high = 0;
    int  low = INT_MAX;
    for(int i : A){
       low = min(low, i);
       high+=i;
    }
    if(high<B) return -1;
    if(B == 1) return high;
    int res = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(canAllocate(A , mid , B)){
           res = mid;
           high = mid-1;
        }else{
            low =mid+1;
        }
    }
    return res;
}
