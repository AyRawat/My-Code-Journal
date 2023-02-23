#include<iostream>
#include<conio>

using namespace std;

  bool checkKthBit(int n, int k)
    {
        // Your code here
        // It can be a one liner logic!! Think of it!!
        n=n>>k;
        if((n&1)==1){
            return true;
        }
        return false;
        
    }

        
int main(){
    return 0;
}