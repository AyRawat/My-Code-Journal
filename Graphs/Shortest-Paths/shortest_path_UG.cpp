#include<bits/stdc++.h>
#include<queue>
using namespace std;

vector<int> shortestDistance(int n, vector<vector<int>> &adj){
    vector<int> visited(n,0);
    vector<int> distance(n, 1e9);
    queue<pair<int,int> > q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> curr = q.front();
        visited[curr.first] = 1;
        q.pop();
        for(auto it: adj[curr.first]){
          if(visited[it]!=1){
            distance[it] = min(distance[it], 1+curr.second);
            q.push({it, 1+curr.second});
            }
          }
      }
      return distance;
  }

int main() {
   vector<vector<int>> adj = {{1,3},{0,2,3},{1,6},{0,4},{3,5},{4,6},{2,5,7,8},{6,8},{6,7}};
   vector<int> result = shortestDistance(9, adj);
   for(int i=0;i<result.size();i++){
      cout<<i<<"--"<<result[i]<<" "<<endl;
    }
    return 0;
  }

