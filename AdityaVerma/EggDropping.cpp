#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > t(1001, vector<int>(1001 , -1));
//Reccursive solution
int solveReccusrsively(int e, int f){
    if(e==0||f==0){
        return -1;
    }
    if(e==1||f==1){
        return f;
    }
   
    int main_ans = INT_MAX;
    for(int K=1; K<=f;K++){
        int temp_ans =  1 + max(solveReccusrsively(e-1,K-1) , solveReccusrsively(e,f-K) );
        main_ans = min(main_ans, temp_ans);
    }
    return t[e][f] = main_ans;
}
//Super Optimized Solution
int solve(int e, int f){
    if(e==0||f==0){
        return -1;
    }
    if(e==1||f==1){
        return f;
    }
    if(t[e][f]!=-1){
        return t[e][f];
    }
    int main_ans = INT_MAX;
    int left=-1,right=-1;
    for(int K=1; K<=f;K++){
        if(t[e-1][K-1]!=-1){
           left = t[e-1][K-1];
        }else{
           left = solve(e-1,K-1);
        }
        if(t[e][f-K]!=-1){
          right = t[e][f-K];
        }else{
          right = solve(e,f-K);
        }
        int temp_ans =  1 + max(left , right);
        main_ans = min(main_ans, temp_ans);
    }
    return t[e][f] = main_ans;
}


int main(){
    cout<<solve(3,998);
    return 0;
}