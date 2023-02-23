#include<iostream>
#include<conio>

using namespace std;

 void tohT(int N, int from, int to, int aux) {
        if(N==0){
            return;
        }
          if(N==1){
            cout<<"move disk "<< from<<" from rod "<< from<< "to rod"<<to<<endl;
            tohT(N-1 ,1,2,3);
            return;
        }
         tohT(N-1,1,3,2);
        cout<<"move disk "<< from<<" from rod "<< from<< "to rod"<<to<<endl;
        tohT(N,3,1,2);
         cout<<"move disk "<< from<<" from rod "<< from<< "to rod"<<to<<endl;
         //return count;
    }

//  long long toh(int N, int from, int to, int aux) {
//         // Your code here
//       return tohT(N,from,to,aux);
//     }
int main(){
   cout<<tohT(3,1,2,3);
    return 0;
}