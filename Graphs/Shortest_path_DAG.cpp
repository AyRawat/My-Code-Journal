#include<bits/stdc++.h>
using namespace std;

void dfs(int V, int N, vector<int> &visited, vector<vector<pair<int,int>>>& adjacency, stack<int> &st){
     visited[V] = 1;
     for(auto it: adjacency[V]){
         if(visited[it.first]!=1) dfs(it.first , N, visited, adjacency, st);
     }
     st.push(V);
 }
 vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // code here
    stack<int> st;
    vector<vector<pair<int,int>>> adjacency(N);
    vector<int> distance(N, 1e9);
    vector<int> visited(N, -1);
    //Create an adjacency list with weights
    for(const auto & it: edges){
        pair<int, int> curr_pair = {it[1], it[2]};
        adjacency[it[0]].push_back(curr_pair);
    }
    for(int i=0;i<N;i++){
      if(visited[i]!=1) dfs(i, N, visited, adjacency, st);    
    }
    distance[0] = 0;
    while(!st.empty()){
        int curr = st.top();
        for(auto it: adjacency[curr]){
            distance[it.first] = min(distance[it.first] , distance[curr] + it.second);
        }
        st.pop();
    }

   for(int i=0; i< distance.size();i++) {
       if(distance[i] == 1e9) distance[i] = -1;
   }
    return distance;
}
int main(){
  return 0;
}