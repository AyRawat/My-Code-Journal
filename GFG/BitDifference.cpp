 #include<iostream>
#include<conio>

using namespace std;
 
 int countBitsFlip(int a, int b){
        int c = a^b;
        int res = 0;
        while(c>0){
            c = c&(c-1);
            res++;
        }
        // Your logic here
        return res;
    }
    int main(){
    return 0;
}