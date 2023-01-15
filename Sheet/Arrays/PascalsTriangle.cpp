#include<bits/stdc++.h>
using namespace std;

//Naiive Soln: Pascal's
void pascal(int N , vector<int> &arr, int index , vector<vector<int>> &result){
 vector<int> level;
 if(N == 1 || N == 2) { 
    for(int i=1; i<=N;i++) {
        level.push_back(1);
    }
    result.push_back(level);
    return ;
    }
if(index == N) return;
level.push_back(1);
for(int i=1;i<arr.size();i++){
level.push_back(arr[i] + arr[i-1]);
}
level.push_back(1);
result.push_back(level);
pascal(N,level,index+1,result);
}

//Print then number present at the given Row and Column of a Pascal Trianlge

int printNum(int row, int col){
    if(row == 1 || row == 2) return 1;
    return  ( (row-1) * (row - 2) ) / ((col-1) * (col - 2));
}

//Print Nth row of a Pascal's triangle


int main () {
    int N = 5;
    vector<vector<int>> result;
    vector<int> arr;
    arr.push_back(1);
    result.push_back(arr);
    cout<< printNum(6 , 3);
    // pascal(N , arr , 1 , result);
    // for(auto i : result){
    //     for(auto j: i){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }
    return 0;
}