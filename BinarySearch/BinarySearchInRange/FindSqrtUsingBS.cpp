#include<bits/stdc++.h>
using namespace std;


int floorSqrt(int n)
{
    // Write your code here.
    int low = 1;
    int high = n;
    while (low <= high) {
       int mid = (low + high ) / 2;
       long long val = mid * mid;
       if (val <= n) {
            low = mid + 1;
            
       } else {
            high = mid - 1;
       }
    }
    return high;
}
int main(){
  return 0;
}
