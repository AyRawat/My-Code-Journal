//https://leetcode.com/problems/find-the-safest-path-in-a-grid/?envType=daily-question&envId=2024-05-15
#include<bits/stdc++.h>

using namespace std;
   int row[4] = {-1,0,1,0};
   int col[4] = {0,1,0,-1};
int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        queue<pair<int,pair<int,int>>> q; 

        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j] == 1) {
              dist[i][j] = 1;
              q.push({1,{i,j}});
            }
          }
        }
        while(!q.empty()){
          auto curr = q.front();
          q.pop();
          int d = curr.first;
          int x = curr.second.first;
          int y = curr.second.second;
          
          for(int i=0;i<4;i++){
            int nR = row[i] + x;
            int nC = col[i] + y;
            if(nR>=0 && nR <m && nC>=0 &&nC<n && grid[nR][nC] == 0){
              if(dist[nR][nC] > d + 1) {
                dist[nR][nC] = d + 1;
                q.push({d+1,{nR,nC}});
              }
            }
          }
        }
     for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
         cout<<dist[i][j]<<" ";
       }
       cout<<endl;
     }
     //Dijkastra
     priority_queue<pair<int,pair<int,int>>> pq;
     pq.push({dist[0][0],{0,0}});
     while(pq.top().second.first<n-1 || pq.top().second.second<n-1){
       auto it = pq.top();
       int dist = it.first;
       int x = it.second.first;
       int y = it.second.second;
       pq.pop();
       for(int i=0;i<4;i++){
         int nR = x + row[i];
         int nC = y + col[i];
         if(nR>=0 && nR<m && nC >=0 && nC<n && visited[nR][nC] != 1){
           pq.push({min(dist, dist[nR][nC]), {nR, nC}});
           visited[nR][nC]  = 1;
         }
       }
     }
        return pq.top().first - 1;
    }


int main(){
  vector<vector<int>> grid = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
  maximumSafenessFactor(grid);
  return 0;}
