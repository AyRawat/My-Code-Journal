#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, int color, vector<int> &visited, vector<vector<int>> &graph){
  if(visited[node]==-1){
    visited[node] = color;
    for(auto it: graph[node]){
      if(visited[it]!=-1 && visited[it]== color){
        return false;
      }else if(visited[it]==-1){
        if(dfs(it, !color, visited, graph)== false) return false;
      }
    }
  }
  return true;
}

bool checkBipartite(vector<vector<int>> &graph){
  int m = graph.size();
  vector<int> visited(m, -1);
  int color = 0;
  for(int i=0;i<m;i++){
    if(visited[i]==-1){
      if(!dfs(i,color,visited,graph)) return false;
    }
  }
  return true;
}

int main(){
  vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
  cout<<"Is Bipartite "<<checkBipartite(graph)<<endl;
  return 0;
}
