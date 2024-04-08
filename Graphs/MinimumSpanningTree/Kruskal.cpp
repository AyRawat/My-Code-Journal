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


int spanningTree(int V, vector<vector<int>> adj[]){
//Sort the edges based on their weight;
vector<pair<int,pair<int,int>> edges;
for(int i=0;i<adj.size();i++){
  int u = i;
  int v = adj[i][0];
  int w = adj[i][1];
  edges.push_back({w,{u,v}});
}
DisjointSet d_set(V);
sort(edges.begin(),edges.end());
//Initialize Parent and Rank arrays;
int spanning_sum = 0;
vector<int> rank(V+1, 1);
vector<int> parent(V+1);
iota(parent.begin(), parent.end(), 1);
for(auto it: edges){
  int wt = it.first;
  int u = it.second.first;
  int v = it.second.second;

  if(d_set.findUPar(u) != d_set.findUPar(v)){
     spanning_sum += wt;
     ds.unionBySize(u,v);
  }

}
return spanning_sum;
}
int main(){
  return 0;
}
