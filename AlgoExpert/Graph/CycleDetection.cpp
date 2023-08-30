#include <vector>
using namespace std;

bool dfs(int V ,vector<vector<int>> edges , vector<int> &visited , vector<int> &path){
  visited[V] = 1;
  path[V] = 1;
  
  for(auto it : edges[V]){
    if(visited[it]!=1){
      if (dfs(it, edges,visited,path) ) return true;;
    }else if(visited[it] && path[it]) return true;
  }
  path[V] = 0;
  return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
  // Write your code here.
  int m = edges.size();
  vector<int> visited(m, 0);
  vector<int> path(m,0);
  bool result;
  for(int i = 0; i < edges.size();i++){
    if (dfs(i, edges, visited, path) ) return true; 
  }
  return false;
}
