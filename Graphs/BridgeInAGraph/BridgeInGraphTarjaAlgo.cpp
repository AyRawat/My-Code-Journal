//https://leetcode.com/problems/critical-connections-in-a-network/
#include<bits/stdc++.h>

using namespace std;

 class Solution {
private:
int timer = 1;
public:
    void dfs(int node,int parent, vector<int> &visited, vector<int> &time, vector<int> &low,vector<vector<int>> &bridges,vector<int> adj[]){
        visited[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
           if(it==parent) continue;
           if(visited[it] == 0){
             dfs(it,node,visited,time,low,bridges,adj);
             low[node] = min(low[node], low[it]);
             if(low[it] > time[node]) bridges.push_back({it,node});
           }else{
             low[node] = min(low[node], low[it]);
           } 
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       //Creat an adjacency matrix
       vector<int> adj[n];
        for(auto it: connections){
          int u = it[0];
          int v = it[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
       }

       //consider two arrays, time and lowest_time[].
       vector<vector<int>> bridges;
       vector<int> time(n);
       vector<int> low(n);
       vector<int> visited(n, 0);
       dfs(0,-1,visited,time,low,bridges,adj);
       return bridges;
    }
}

int main(){
  return 0;
}
