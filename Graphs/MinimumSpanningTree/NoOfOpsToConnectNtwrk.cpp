#include<bits/stdc++.h>
using namepsace std;

class DisjointSet {
  public: 
  vector<int> size,parent;
  DisjointSet(int n){
      size.resize(n+1);
      parent.resize(n+1);
      for(int i=0;i<n;i++){
        size[i] = 1;
        parent[i] = i;}
  }
  int findUParent(int node){
    if(parent[node] == node) return node;
    return parent[node] = findUParent(parent[node]);
  }
  void unionBySize( int u,  int v){
    int ult_parent_u = findUParent(u);
    int ult_parent_v = findUParent(v);
    if(ult_parent_u == ult_parent_v) return;
    if(size[ult_parent_u] > size[ult_parent_v]){
      parent[ult_parent_v] = ult_parent_u;
      size[ult_parent_u] += size[ult_parent_v];
    }else {
      parent[ult_parent_u] = ult_parent_v;
      size[ult_parent_v]+= size[ult_parent_u];
    }
  }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dSet(n);
         int spanning_sum = 0;
        for(auto it: connections){
          int u = it[0];
          int v = it[1];
          if(dSet.findUParent(u) != dSet.findUParent(v)){
            dSet.unionBySize(u,v);
            spanning_sum++;
        }
    }
        //if(connections.size() -  spanning_sum >= (n-1 - spanning_sum)) return (n-1 - spanning_sum);
        return connections.size() - spanning_sum >= (n-1 - spanning_sum) ? (n-1 - spanning_sum) : -1;
    }
}
int main(){
  return 0;
}
