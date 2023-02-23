// Given a number N. The task is to check whether it is sparse or not.
// A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.
#include<iostream>
#include<conio>

using namespace std;
  
  //Function to check if the number is sparse or not.
    bool isSparse(int n)
    {
        // Your code
        int bit = 0;
        while(n>0){
            if(n&(n>>1)){
                return false;
            }
            n=n>>1;
        }
        return true;
    }

 int main()
 {
    return 0;
}