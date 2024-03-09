#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int V, vector<vector<int>> adj[], int S){
  //Declare a min heap which will keep minimum distance at the top
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq;
  vector<int> distance(V,1e9);
 distance[S] = 0;
  pq.push({0,S});
  while(!pq.empty()){
    int curr_node = pq.top().second;
    int curr_distance = pq.top().first;
    pq.pop();
    for(auto it: adj[curr_node]){
      int node = it[0];
      int node_distance = it[1];
      if(node_distance+curr_distance < distance[node]){
        distance[node] = node_distance + curr_distance;
      pq.push({node_distance+curr_distance, node});
      }
    }
  }
  return distance;
}
 
int main(){
  return 0;
}
