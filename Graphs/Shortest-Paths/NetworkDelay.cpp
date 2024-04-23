   int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     //Create an adjacency matrix
     vector<vector<pair<int,int>>> adj(n+1);
     for(auto it: times){
      adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,int>>  pq;
    vector<int> distance(n+1,1e9);
    distance[k] = 0;
    pq.push({0,k});

    while(!pq.empty()){
      auto curr = pq.front();
      pq.pop();
      int curr_node = curr.second;
      int curr_wt = curr.first;

      for(auto it: adj[curr_node]){
        int adjNode = it.first;
        int adjWt = it.second;
        if(distance[adjNode] > adjWt + curr_wt){
          distance[adjNode] = adjWt + curr_wt;
          pq.push({distance[adjNode], adjNode});
        }
      }
    }
   int min_time = -1;
   for(int i=1;i<=n;i++){
    if(distance[i] == 1e9) {
      min_time = -1;
      break;
    }
    min_time = max(min_time, distance[i]);
   }
   return min_time;
   }
