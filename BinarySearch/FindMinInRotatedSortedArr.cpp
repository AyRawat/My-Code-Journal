#include<bits/stdc++.h>
using namespace std;


   int findMin(int arr[], int n) {
        // complete the function here
        int lo =0;
        int hi = n-1;
        int min_val = INT_MAX;
        
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            min_val = min(arr[mid], min_val);
            if(arr[mid] > arr[lo]){
                min_val = min (min_val, arr[lo]);
                //Time to eliminate the sorted half
                lo = mid+1;
            }else{
                min_val = min(min_val, arr[hi]);
                hi = mid-1;
            }
        }
        return min_val;
    }

int main(){
  return 0;
}
