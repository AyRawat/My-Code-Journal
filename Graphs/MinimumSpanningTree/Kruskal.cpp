#include<bits/stdc++.h>

using namespace std;


class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
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
