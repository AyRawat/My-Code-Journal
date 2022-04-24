/*
For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
*/
#include<bits/stdc++.h>
using namespace std;

long long merge(long long *arr, long long *temp, int left, int mid, int right){
	int i = left;
	int j = mid;
	int k = right;
	long long inv_count = 0;
	while((i<=mid-1)&&(j<=right)){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			//as mid stands for the left sorted array's length;
			inv_count += (mid - i);
		}
	}
	while(i<=mid-1){
		temp[k++] = arr[i];
	}
	while(j<=right){
		temp[k++] = arr[j];
	}
	for(int i= left; i<=right;i++){
		arr[i] = temp[i];
	}
	return inv_count;
}

long long mergeSort(long long* arr,long long* temp, int left, int right){
	long long mid;
	long long inv_count = 0;
	if(right > left){
		mid = (right + left) / 2;
	    inv_count += mergeSort(arr,temp,left,mid);
		inv_count += mergeSort(arr,temp, mid+1, right);
		inv_count += merge(arr, temp,left,mid,right);
	}
	return inv_count;
}


int main(){
    return 0;
}