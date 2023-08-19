#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector<int> row = {0,1,-1,0};
vector<int> col = {1,0,0,-1};
int bfs(int i, int j, vector<vector<int>> &v , vector<vector<int>> &matrix,int m, int n,int len){
  v[i][j] = 1;
  for(int k = 0; k<4;k++){
    int currR = i + row[k];
    int currC = j + col[k];
    int val = 1;
    if(currR>=0 && currR <m && currC >=0 && currC < n && v[currR][currC]==0 && matrix[currR][currC] == 1){
      len = 1 + bfs(currR,currC,v,matrix,m,n,len);
    }
  }
  return len;
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  // Write your code here.
  int m = matrix.size();
  int n = matrix[0].size();
  vector<int> result;
  vector<vector<int>> visited(m, vector<int>(n, 0));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==1 && visited[i][j]!=1){
          int res = bfs(i,j,visited,matrix,m,n,1);
          result.push_back(res);
            for(auto it: result){
          cout<<it<<" ";
  }
  cout<<endl;
        }
    }
  }
  return result;
}
