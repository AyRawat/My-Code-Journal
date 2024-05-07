#include<bits/stdc++.h>
using namespace std;



class DisjointSet {
  public:
  vector<int> parent,size;
  DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
      parent[i] = i;
      size[i] = 1;
    }}
    
    int findParent(int node) {
      if(node == parent[node]) return node;
      return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u , int v){
       int ult_u = findParent(u);
       int ult_v = findParent(v);
       if(ult_u == ult_v) return;

       if(size[ult_u] < size[ult_v]) {
          parent[ult_u] = ult_v;
          size[ult_v] += size[ult_u]; 
       }else{
          parent[ult_v] = ult_u;
          size[ult_u] += size[ult_v];
       }
    }
  };
class Solution {
public:
    bool checkValid(int i, int j, int n){
        if(i>=0 && i<n && j>=0 &&j <n) return true;
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DisjointSet dSet(n*n);

        int dR[] = {-1,0,1,0};
        int dC[] = {0,1,0,-1};
        
        //Step 1 :- Identofy all the island Groups
        for(int r = 0; r < n; r++){
          for(int c = 0; c < n; c++){
            if(grid[r][c] == 1){
              for(int k=0;k<4;k++){
                int nR = dR[k] + r;
                int nC = dC[k] + c;
                if(checkValid(nR, nC, n) && grid[nR][nC] == 1) {
                  int node = r * n + c;
                  int adjNode= nR * n + nC;
                  dSet.unionBySize(node,adjNode);
                }
              }
            }
          }
        }
        //To check whether all are islands, and there are no 0s
     int max_island_size = 1;

               for (int i = 0; i < n * n; i++) {
   max_island_size = max(max_island_size, dSet.size[i]);
  }
        //Step 2 :- Traverse and see what all island groups can be joined
   
        for(int i=0; i<n;i++){
          for(int j=0; j<n;j++){
            unordered_set<int> islands;
            if(grid[i][j] == 0){
             for(int k=0;k<4;k++){
              int nR = dR[k] + i;
              int nC = dC[k] + j;
              if(checkValid(nR, nC, n) && grid[nR][nC] == 1){
                islands.insert(dSet.findParent(nR*n + nC));
              }
             }
             int t_size = 0;
              for(auto it: islands){
                t_size += dSet.size[it];
              }
             max_island_size = max(max_island_size, t_size + 1);
            }
          }
        }
        return max_island_size;
    }
};
int main(){
  return 0;
}
