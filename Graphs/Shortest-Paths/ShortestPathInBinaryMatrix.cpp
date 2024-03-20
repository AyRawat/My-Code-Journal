    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0] == 1) return -1;
    if(grid.size() == 1 && grid[0][0] == 0) return 1;
    queue<pair<int,pair<int,int>>> pq;
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rows = {0,1,-1,0,1,-1,-1,1};
    vector<int> cols = {-1,0,0,1,1,-1,1,-1};
    vector<vector<int>> distance(m, vector<int>(n,1e9));
    pq.push({1,{0,0}});
    distance[0][0] = 0;
    while(!pq.empty()){
     auto curr = pq.front();
     int d = curr.first;
     int x = curr.second.first;
     int y = curr.second.second;
     pq.pop();  
     for(int i=0;i<rows.size();i++){
      for(int j=0;j<cols.size();j++){
        int newR = rows[i]+x;
        int newC = cols[j]+y;
         if(newR>=0 && newR <m && newC >=0 && newC < n && grid[newR][newC] == 0&& d+1 < distance[newR][newC]){
            distance[newR][newC] = d + 1;
            if(newR == m-1 && newC == n-1) return distance[newR][newC];
            pq.push({d+1,{newR,newC}});
         }
      }
     }
    }  
    return -1;   
    
