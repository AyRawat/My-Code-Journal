#include<bits/stdc++.h>

using namespace std;

 int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>> adj(n,vector<int>(n,1e9));
    for(int i=0; i< n;i++){
        adj[i][i] = 0;
    }
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u][v] =d;
            adj[v][u] = d;
        }
       for(int k=0;k<n;k++){ 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][k] == 1e9 || adj[k][j] == 1e9) continue;
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
            }
         }
       }
    
       int count_max = n;
       int city = -1;
       for(int i=0; i < adj.size();i++){
           int count = 0;
           for(int j=0;j<adj[0].size();j++){
               if(i == j) continue;
               if(adj[i][j] <= distanceThreshold) count++;
           }
           if(count <= count_max){
               count_max = count;
               city = i;
           }
       }
       return city;
    }
int main(){
  return 0;
}
