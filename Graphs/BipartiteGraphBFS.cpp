#include<bits/stdc++.h>

using namespace std;

bool isBipartite(int start, vector<int>& visited, vector<vector<int>> &adj){
  queue<int> q;
  q.push_back(start);
  visited[start] = 0;
  while(!q.empty()){
   int curr = q.front();
  q.pop();
  for(auto it: adj[curr]){
    if(visited[it]==-1){
     visited[it] = !visited[curr];
    }else if(visited[it] == visited[curr]){
      return false;
    }
  }
  }
  return true;
}

bool handler(vector<vector<int>> &adj){
  int m = adj.size();
  vector<int> visited(m, -1);

  for(int i=0; i< m;i++){
    if(visited[i]!=-1){
      if(!isBipartite(i,visited,adj)) return false;
    }
  }
  return true;
}
int main(){
  
  return 0;
}
