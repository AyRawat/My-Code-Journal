#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
   void solve(vector<vector<int>> &matrix, int i, int j, int m, int n){
        cout<<i<<j<<m<<n;
        for(int x=0;x<n;x++){
            matrix[i][x]=0;
        }
        for(int y=0;y<m;y++){
            matrix[y][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> zeroIndex;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
     zeroIndex.push_back({i,j});
                }
            }
        }
        for(int i=0;i<zeroIndex.size();i++){
            solve(matrix,zeroIndex[i][0],zeroIndex[i][1],m,n);
        }
    }
//Best Approach
void solveBest(vector<vector<int>> &matrix){
    int col0 = 1;int row = matrix.size(); int col = matrix[0].size();
for(int i=0;i<row;i++){
    if(matrix[i][0] == 0) col0 = 0;
    for(int j=1;j<col;j++){
        if(matrix[i][j] == 0){
            matrix[i][0] =matrix[0][j]= 0;
        }
    }
}
for(int i = row - 1 ; i>=0;--i){
    for(int j = col-1;j>=1;j--){
        if(matrix[i][0] == 0 || matrix[0][j] == 0){
            matrix[i][j] = 0;
        }
    } 
    if(col0 == 0) matrix[i][0]=0;
}
}


int main(){

    return 0;
}