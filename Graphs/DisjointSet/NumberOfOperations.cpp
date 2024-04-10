//Problem Statement: You are given a graph with n vertices and m edges. 
//You can remove one edge from anywhere and add that edge between any two vertices in one operation. 
//Find the minimum number of operations that will be required to make the graph connected. 
//If it is not possible to make the graph connected, return -1.
//https://www.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph



class DisjointSet {
    
    public: 
       vector<int> size,parent;
       DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
       }
       int findParent(int u){
           if(parent[u] == u) return u;
           return parent[u] = findParent(parent[u]);
       }
       void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet d_set(n);
        int extra_edges = 0;
        int numComponents = 0;
        for(int i=0; i <edge.size();i++){
                int u = edge[i][0];
                int v = edge[i][1];
                if(d_set.findParent(u) == d_set.findParent(v)) extra_edges++;
                else
                  d_set.unionBySize(u , v);
        }
        //Count the number of components;
        for(int i=0; i< n;i++){
            if(d_set.parent[i] == i) numComponents++;
        }
        int edgesRequired = numComponents - 1;
        if(edgesRequired >= extra_edges) return edgesRequired;
        return -1;
    }
};
