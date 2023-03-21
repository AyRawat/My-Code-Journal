#include<bits/stdc++.h>
using namespace std;


   void dfs(int V, vector<int> adj[] , vector<int> &visited){
        visited[V] = 1;
        for(auto it: adj[V]){
          if(!visited[it]){
             dfs(it, adj,visited);  
          }    
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adj_l[V];
        vector<int> visited(V, 0);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                adj_l[i].push_back(j);
                adj_l[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i=0;i<V;i++){
             if(!visited[i]){
                 count++;
                 dfs(i, adj_l, visited);
             }
        }
        return count;
    }

int main(){
  return 0;
}