//Given a non-negative integer N. The task is to check if N is a power of 2.
// More formally, check if N can be expressed as 2x for some x.


#include<iostream>
#include<conio>

using namespace std;

 bool isPowerofTwo(long long n){
        int count = 0;
        // Your code here    
        while(n>0){
            if((n&1)==1){
                count++;
            }
            n=n>>1;
        }
        if(count==1){
            return true;
        }else{
            return false;
        }
    }

    int main(){
        return 0;
    }
