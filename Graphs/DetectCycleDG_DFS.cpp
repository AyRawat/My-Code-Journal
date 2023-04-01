#include<bits/stdc++.h>

using namespace std;

   // Function to detect cycle in a directed graph.
    bool dfs(int V, vector<int> &visited , vector<int> &path, vector<int> adj[]){
        visited[V] = 1;
        path[V] = 1;
        for(auto it: adj[V]){
            if(!visited[it]){
                if(dfs(it, visited,path,adj)) return true;;
            }else if(visited[it] && path[it]){
                return true;
            }
        }
        path[V] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> path(V, 0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, visited,path,adj)) return true;
            }
        }
        return false;
    }

int main(){
  vector<int> adj[] ={{2}, {3},{4,7},{5},{6},{-1}, {5},{2,9},{10}, {8}};
  bool answer(checkCycle(10,adj));
  cout<<answer;
  return 0;
}