#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll NumberOfWays(int n, vector<vector<int>> &graph){
                 //Create an adjacency list
  vector<pair<ll,ll>> adj[n];
  for(auto it: graph){
    adj[it[0]].push_back({it[1], it[2]});
    adj[it[1]].push_back({it[0],it[2]});
  }
  //A priority Q;
  priority_queue<
   pair<ll,int>,
   vector<pair<ll,int> >,
   greater<pair<ll,int> > > pq;

  pq.push({0,0});
  //A distance array
  vector<ll> distance(n,LLONG_MAX);
  distance[0] = 0;
  //A ways array to keep a track of all the ways that can reach to
  //the destination, till that poll of time.
  vector<ll> ways(n, 0);
  ways[0] = 1;
  ll mod = (int)(1e9 + 7);
  //Start Dijkastra
  while(!pq.empty()){
   ll wt = pq.top().first;
   ll node = pq.top().second;
   pq.pop();
   for(auto it: adj[node]){
     ll adjNode = it.first;
     int edWt = it.second;
     if(distance[adjNode] > edWt + wt){
       distance[adjNode] = edWt + wt;
       pq.push({distance[adjNode], adjNode});
       ways[adjNode] = ways[node];
     }else if(distance[adjNode] == edWt + wt){
       ways[adjNode] = (ways[node]+ ways[adjNode]) % mod;
     }
   }
  }
  return ways[n-1]%mod;
}

int main(){
  return 0;
}
