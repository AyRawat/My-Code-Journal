#include<bits/stdc++.h>
using namespace std;


class DisjointSet {
  vector<int> rank, parent, size;
  public: 
      DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);
        iota(parent.begin(), parent.end(), 1);
      }
      //Find the ultimare parent
      int findUPar(int node){
        if(node == parent[node]) return node;
        //Path Compression
        return parent[node] = findUPar(parent[node]);
      }
      void unionByRank(int u, int v){
        int uParentU = findParent(u);
        int uParentV = findParent(v);
        //If they belong to the same parent;
        if(uParentU == uParentV) return;

        int uRank = rank[uParentU];
        int vRank = rank[uParentV];
      //If the rank is either small or large. Just switch up the parents. And Rank will remain same
      //as we are only adding to the same level.
      if(uRank < vRank){
        parent[uParentU] = uParent[V]; 
      }else if(uRank > vRank){
        parent[uParentV] = uParentU;
      }else{
        //If the rank is same, then you need to increase it after the union of u to v.
        parent[uParentV] = uParentU;
        rank[uParentU]++;
      }
      void unionBySize(int u, int v){
        int uParentU = findParent(u);
        int uParentV = findParent(v);
        if(uParentU == uParentV) return;

        int uSize = size[uParentU];
        int vSize = size[uParentV];
        if(uSize < vSize){
          parent[uParentU] = uParentV;
          size[uParentV] += size[uParentU];
        }else{
          parent[uParentV] = uParentU;
          size[uParentU]+= size[uParentU];
        }
      }
};
int main(){
  return 0;
}
