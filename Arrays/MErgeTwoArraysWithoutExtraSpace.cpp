#include<bits/stdc++.h>
using namespace std;
//These Two arrays are sorted in themeselves

//T.C : O(n*m)
//S.C : O(1)
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int x,y;
        x=m-1;
        y=n-1;
        int k= m+n-1;
        while(x >=0 && y >=0){
            if(nums1[x] > nums2[y]){
                nums1[k--] = nums1[x--];
            }else{
                nums1[k--] = nums2[y--];
            }
        }
        while(x>=0){
            nums1[k--] = nums1[x--];
        }
        while(y>=0){
            nums1[k--] = nums2[y--];
        }
        
    }

//T.C: O(logN)
//S.C: O(1)
//The Gap Method GFG Link to problem :https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int gap = ceil((float)(m+n)/2);
    
    while(gap!=0){
    int i = 0;
    int j = gap;
    while(j < (m+n) ){
        //Case 1: When both i and j are inside array 1;
      if(i<m && j<m && nums1[i] > nums1[j]){
          swap(nums1[i] , nums1[j]);
        //Case 2 i is in array 1 and j is in array 2
      }else if(i<n && j>=n && nums1[i] > nums2[j-m]){
        swap(nums1[i] , nums2[j-n]);
        //Case 3 i is in array 2 and j is in array 2;
      }else if((i >=n && j>=n &&  nums2[i-m] > nums2[j-m])){
          swap(nums2[i] , nums2[j]);
      }
      i++;
      j++;
    }
    if(gap==1){gap = 0;}
    else {gap = ceil((float)gap/2);}
    }
}

int main(){
return 0;
}