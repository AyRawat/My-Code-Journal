  
   #include<iostream>
#include<conio>

using namespace std;
   int maxConsecutiveOnes(int N)
    {
        // code here
        int len = 0;
        int maxLen = 0;
        while(N>0)
        {
            if((N&1)== 1)
            {
                len++;
                maxLen = max(len,maxLen);
            }else{
                maxLen = max(len,maxLen);
                len=0;
            }
            N=N>>1;
        }
        return maxLen;
    }
//More Efficient
    int maxConsecutiveOnes(int N)
    {
     
        int count = 0;
     
      //We use a loop to perform AND operation on N and N<<1 and everytime the 
      //trailing 1 from every sequence of consecutive 1s is removed.
      //Loop continues till N is reduced to 0.
       while (N!=0)
        {
           //Assigning result of AND operation to N
            N = (N & (N << 1));
           //increement of counter variable.
            count++;
        }
        //returning the answer.
        return count;
    }
     int main(){
    return 0;
}