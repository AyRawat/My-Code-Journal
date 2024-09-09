#include<bits/stdc++.h>

using namespace std;

double median(vector<int>& a, vector<int>& b) {␍
	// Write your code here.␍
	int size1 = a.size();␍
	int size2 = b.size();␍
	int n = (size1 + size2);␍
	int ind2 = n/2;␍
	int ind1 = ind2-1;␍
	int ind1element = -1;␍
	int ind2element = -1;␍
	int i = 0;
	int j = 0;
    int count = 0;␍
        while (i < size1 && j < size2) {␍
		 if(a[i] <= b[j]){␍
            if(count == ind1) ind1element = a[i];␍
			if(count == ind2) ind2element = a[i];␍
			count++;␍
			i++;␍
                 } else {␍
			if(count == ind1) ind1element = b[j];␍
			if(count == ind2) ind2element = b[j];␍
			count++;␍
			j++;		 ␍
        }␍
       }␍
	    while (i < size1) {␍
		  if(count == ind1) ind1element = a[i];␍
		  if(count == ind2) ind2element = a[i];␍
          count++;␍
		  i++;  ␍
		}␍
        while (j < size2) {␍
           	if(count == ind1) ind1element = b[j];␍
			if(count == ind2) ind2element = b[j];      ␍
			count++;␍
			j++;␍
		}␍
		if(n%2 == 1) return ind1element;␍
		return (double)((double)(ind1element + ind2element) ) / 2.0;␍
 }
int  main(){
  return 0;
}
