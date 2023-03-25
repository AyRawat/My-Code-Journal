#include<bits/stdc++.h>
using namespace std;
    bool detectCycleDFS(int src,int parent, vector<int> adj[] ,int vis[]){
        vis[src] = 1;
        for(auto it: adj[src]){
            if(!vis[it]){
               if(detectCycleDFS(it, src ,adj, vis)) return true;
            }else if(vis[it] && it != parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycleDFS(i,-1, adj,visited)) return true;
            }
        }
        return false;
    }
int main(){
  return 0; 
}