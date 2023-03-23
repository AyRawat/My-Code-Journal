#include<bits/stdc++.h>

using namespace std;

    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        queue< pair<pair< int , int > , int > > q;
        int minTime = INT_MIN;
        vector<vector<int>> visited(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({{i , j},0});
                    visited[i][j] = 2;
                }else{
                    visited[i][j] = 0;
                }
            }
        }
        int dirR[] = {-1,0,+1,0};
        int dirC[] = {0,+1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            minTime = max(t , minTime);
            q.pop();
            for(int i=0;i<4;i++){
                int nR = r + dirR[i];
                int nC = c + dirC[i];
                if(nR>=0 && nR<m && nC >= 0 && nC < n && visited[nR][nC]!=2 && grid[nR][nC] == 1){
                    q.push({{nR,nC},t+1});
                    visited[nR][nC] = 2;
                }
            }
        }  
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]!=2 && grid[i][j] == 1) return -1;
            }
        }
        return minTime;
    }