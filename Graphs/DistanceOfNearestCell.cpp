#include<bits/stdc++.h>
using namespace std;

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>> oGrid = grid;
	    vector<vector<int>> visited(m, vector<int>(n,0));
	    queue<pair<pair<int,int> , int>> q;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j] == 1){
	            visited[i][j] = 1;
	            q.push({{i,j},0});
	            }
	        }
	    }
	    int d_Row[] = {-1,0,1,0};
	    int d_Col[] = {0,1,0,-1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int distance = q.front().second;
	        q.pop();
	        oGrid[row][col] = distance;
	        for(int i=0;i<4;i++){
	            int dRow = row + d_Row[i];
	            int dCol = col + d_Col[i];
	            if(dRow>=0 && dRow<m && dCol>=0 &&dCol<n && visited[dRow][dCol]==0 && grid[dRow][dCol]==0){
	                visited[dRow][dCol] = 1;
	                q.push({{dRow, dCol}, distance+1});
	            }
	        }
	    }
	    return oGrid;
	}

int main(){
  return 0;
}