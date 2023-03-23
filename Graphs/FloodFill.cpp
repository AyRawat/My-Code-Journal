#include<bits/stdc++.h>
using namespace std;


    void dfs(vector<vector<int>>& image,vector<vector<int>>& result , int i,int j, 
    int newCol,int delRow[] ,int delCol[], int iniCol){
        result[i][j] = newCol;
        int m = image.size();
        int n=image[0].size();
        for(int x=0;x<4;x++){
           int nrow = i + delRow[x];
           int ncol = j + delCol[x];
             if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==iniCol
             && result[nrow][ncol] != newCol){
                 dfs(image,result,nrow,ncol,newCol,delRow,delCol,iniCol);
             }
        } 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int iniCol = image[sr][sc];
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        vector<vector<int>> ans = image;
        dfs(image,ans,sr,sc,newColor,delRow,delCol,iniCol);
        return ans;
    }

int main(){
  
  return 0;
}