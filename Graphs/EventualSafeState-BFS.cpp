#include<bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int states = graph.size();
    vector<vector<int>> adj(states);
    for(int i=0;i<states;i++){
      for(auto it: graph[i]){
        adj[it].push_back(i);
      }
    }
    vector<int> indeg(states, 0);
    queue<int> q;
    vector<int> safe_states;
    for(int i=0;i<states;i++){
      for(auto it: adj[i]){
        indeg[it]++;
      }
    }
    for(int i=0;i<states;i++){
      if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
      int node = q.front();
      q.pop();
      safe_states.push_back(node);
      for(auto it: adj[node]){
        indeg[it]--;
        if(indeg[it] == 0) q.push(it);
      }
    }

     sort(safe_states.begin(), safe_states.end());
     return safe_states;
}
int main(){
  return 0;
}