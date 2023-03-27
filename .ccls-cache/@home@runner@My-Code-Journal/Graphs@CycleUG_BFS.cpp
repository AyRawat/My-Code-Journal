#include<bits/stdc++.h>
using namespace std;

    bool detectCycle(int src, vector<int> adj[] , int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node});
                }else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(i, adj,visited)) return true;
            }
        }
        return false;
    }
 
int main(){
  return 0;
}