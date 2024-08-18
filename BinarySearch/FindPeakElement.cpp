#include<bits/stdc++.h> 
using namespace std;

//PEAK element  = arr[i-1] < arr[i] > arr[i+1];
//If the array is completely sorted in ascending order then, last element is the peak
//If array is sorted in desc, then first element is the peak
//So, we already check these cases and get them out of the way, so that we don't need to
//check for array out of bounds edge cases

  int findPeakElement(vector<int>& arr) {
       int n = arr.size();
       if(n == 1 || arr[0] > arr[1]) return 0;
       if(arr[n-1] > arr[n-2]) return n-1;
       int low = 1;
       int high = n - 2;
       
       while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
        if(arr[mid] > arr[mid-1]){
          low = mid + 1;
        }else {
          high = mid  - 1;
        }
       } 
       return -1;
    }


int main(){
  return 0;
}
