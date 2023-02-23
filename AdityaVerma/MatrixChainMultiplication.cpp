#include<bits/stdc++.h>
#include<vector>

using namespace std;

//Reccusrsive SOlution
int MCM(vector<int> arr, int i, int j){
    //Even if i==j, we will have only one matrix to perform the multiplication
     //which is not possible, Therefore base condition includes an equal to sign.
    if(i>=j){
        return 0;
    }
    int minMul = INT_MAX;
    for(int K=i; K<=j-1;K++){
        int tempAns =  MCM(arr,i,K) + MCM(arr,K+1,j) +arr[i-1]*arr[K]*arr[j];
        if(tempAns < minMul){
            minMul = tempAns;
        }
    }
    return minMul;

}
 int t[600][600];
 
int memMCM(vector<int> arr, int i, int j){
   if(i>=j){
       return 0;
   }
   if(t[i][j]!=-1){
       return t[i][j];
   }
   int minMul = INT_MAX;
   for(int K=i ; K=j-1;K++){
       int tempAns = memMCM(arr,i,K) + memMCM(arr,K+1,j) + arr[i-1]*arr[K]*arr[j];
       minMul = min(minMul, tempAns);

}
      return t[i][j] = minMul;
}

int main(){
   memset(t,-1,sizeof t);
   vector <int> a = {40,20,30,10,30};
   cout<< memMCM(a,1,a.size()-1);
    return 0;
}