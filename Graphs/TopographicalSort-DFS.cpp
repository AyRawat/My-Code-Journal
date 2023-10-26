#include<bits/stdc++.h>
using namespace std;
void dfs(int V, vector<int> &visited, stack<int> &st, vector<int> adj[]){
    visited[V] = 1;
    for(auto it: adj[V]){
        if(visited[it]!=1) dfs(it, visited,st,adj);
    }
    st.push(V);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<int> visited(V, 0);
    vector<int> result;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(visited[i]!=1) dfs(i, visited,st,adj);
    }
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    return result;
}