#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<int> &visited, stack<int> & st, vector<int> &adj[]){
  if(!visited[node]){
    visited[node] = 1;
   for(auto it: adj[node]){
     if(!visited[it]){
       dfs(it, visited,st,adj);
     }
   }
  }
    st.push(node);
}

void dfs2(int node,vector<int> &visited, vector<int> &adj[]){
if(!visited[node]){
  visited[node] = 1;
  for(auto it: adj[node]){
    if(!visited[it]) dfs(it, visited,adj);
  }
}
}

int kosaraju(int V, vector<int> adj[]){
 //Step 1, get the finishing and starting time.
  vector<int> visited(V,0);
 stack<int> st;
 for(int i=0;i<V;i++){
   if(!visited[i]) dfs(i,visited,st,adj);
 }
 //Reverse the Graph
 vector<int> rev_graph[V];
 //We need to make sure our visited array is reusable again.
 for(int i=0; i<V;i++){
   visited[i] = 0;
   for(int j=0;j<adj[i].size();j++){
     rev_graph[adj[i][j]].push_back(i);
   }
 }
 
 int strongComponentCount = 0;
 while(!st.empty()){
   int curr = st.top();
   st.pop();
   if(!visited[curr]){
    strongComponentCount++;
    dfs2(curr, visited, st, rev_graph);
   }
 }
 return strongComponentCount;
}

int main()
  return 0;
}
