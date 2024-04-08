#include<bits/stdc++.h>

using namespace std;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<int> visited(V,0);
        vector<pair<int,int>> MST;
        pq.push({0,{0,-1}});
        while(!pq.empty()){
            auto curr = pq.top();
           
            pq.pop();
            int wt = curr.first;
            int node = curr.second.first;
            int parent = curr.second.second;
            if(visited[node] == 1) continue;
             visited[node] = 1;
            if(parent != -1) {
                MST.push_back({parent,node});
                sum+=wt;
            }
            for(auto it :adj[node]){
                if(visited[it[0]] != 1){
                    pq.push({it[1], {it[0],node}});
                }
            }
    }
    return sum;}

int main(){
  return 0;
}
