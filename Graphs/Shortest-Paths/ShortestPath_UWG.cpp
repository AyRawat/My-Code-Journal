#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath(int src,int n, vector<vector<int>> &graph){
  //Convert the graph into adjacency list
  
  //Min Heap
  priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int>>> pq; 
  vector<int> distance(n,1e9);
  vector<int> parent(n);
  iota(vec.begin() , vec.end(), 1);
  pq.push({0,src});
  distance[src] = 0;
  parent[src] = 1;
  while(!pq.empty()){
   int curr_node = pq.front().second;
   int curr_dist = pq.front().first;
   pq.pop();
   for(auto it: graph[curr_node]){
   int node = it[H]
     if(curr_dist + dist[it] < dist[it] ){
     parent[it] = curr_node;
     distance[it] = curr_dist + distance[it];
    }
   }
  }
}
int main(){
  return 0;

