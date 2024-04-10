#include<bits/stdc++.h>
using namespace std;
//count = 0;
//For every element check its 4 directions and see if there are any islands connecting to it.
//If : No nearby islands increase count++ and mark it in the visited array;
//else if curr component can connect to form an island then we decrease the count .
//*Connection means Union here iff P(u) != P(v)
//


class DisjointSet {
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if(ult_u == ult_v) return;
        int size_u = size[ult_u];
        int size_v = size[ult_v];
        if(size_u < size_v){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
bool checkValid(int n, int m, int r, int c){
  if(r>=0 && r<n && c>=0 &&c<m) return true;
  return false;
}
vector<int> numOfIslands(int n, in m, vector<vector<int>> &operators){
 //Every Node in the Matrix will have its corresponding ID, which in turn will be updated in DisjointSet.
  DisjointSet ds(n*m);
  vector<vector<int>> visited(n, vector<int>(m,0));
  vector<int> islands;
  int islandCount =0;
  for(auto it: operators){
    int row = it[0];
    int col = it[1];
    //If it is already visited, then that means, we have already completed counting one island;
    if(visited[row][col] == 1) {
    islands.push_back(islandCount);
    continue;
     }
    visited[row][col] = 1;
    islandCount++;
    vector<int> dr = {0,1,-1,0};
    vector<int> dc = {-1,0,0,1};
    for(int i=0;i<4;i++){
      int adjR = dr[i] + row;
      int adjC = dc[i] + col;
    if(checkValid(n,m,adjR,adjC) && visited[adjR][adjC] == 1){
      //We need to figure out the current row and the adjNode that we are trying to merge, so this is the formula for getting that
      //rowIndex * m + colIndex;
      int nodeNo = row * m + col; 
      int adjNodeNo = adjR *m + adjC;
      if(ds.findParent(nodeNo) != ds.findParent(adjNodeNo)){
        islandCount--;
        ds.unionBySize(nodeNo, adjNodeNo);
      }
    }
    }islands.push_back(islandCount);
  }
return islands;
}
int main(){
  return 0;
}
