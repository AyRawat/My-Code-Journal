#include<bists/stdc++.h>

using namespace std;

findTarget(vector<int> &arr, int n, int target){
  int low = 0;
   int high = n-1;
   while(low <= high){
     int mid = (low + high)/2;
     if(arr[mid] == target) return mid;
     //Check which side is sorted
     if(arr[low] <= arr[mid]){
       if(arr[low] <= target && target <= arr[mid]){
       high = mid - 1;
       }else{
         low = mid + 1;
       }
     }else{ 
       if(arr[mid] <= target && target <= arr[high]){
         low = mid + 1;
       }else{
         high = mid - 1;
       }
     }
   }
return -1;
}


int main(){
   return 0;
 }
