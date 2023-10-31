#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &pathVisited, vector<int> &checkVisited,
         vector<int> &visited, vector<int> adj[]) {
  visited[node] = 1;
  pathVisited[node] = 1;
  for (auto it : adj[node]) {
    if (visited[it] != 1) {
      if (dfs(it, pathVisited, checkVisited, visited, adj) == true)
        return true;
    } else if (visited[it] == 1 && pathVisited[it] == 1)
      return true;
  }
  pathVisited[node] = 0;
  checkVisited[node] = 1;
  return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
  // code here
  vector<int> visited(V, 0);
  vector<int> pathVisited(V, 0);
  vector<int> checkVisited(V, 0);
  vector<int> result;
  vector<int> path;
  for (int i = 0; i < V; i++) {
    if (visited[i] != 1) {
      dfs(i, pathVisited, checkVisited, visited, adj);
    }
  }
  for (int i = 0; i < checkVisited.size(); i++) {
    if (checkVisited[i] == 1)
      result.push_back(i);
  }
  sort(result.begin(), result.end());
  return result;
}