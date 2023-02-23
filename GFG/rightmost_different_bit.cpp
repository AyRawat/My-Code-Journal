#include<iostream>
#include<conio>

using namespace std;
    
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        if(m==n){
            return -1;
        }
        int x = m^n;
        int res;
        while(x>0){
            if((x&1)==1){
                res++;
                break;
            }
            res++;
            x=x>>1;
        }
        return res;
    }

    
int main(){
    return 0;
}