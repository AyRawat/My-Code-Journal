#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    queue<vector<int> > q;
    //Total time taken to rot
    int total_time_taken = 0;
    //The number of oranges that we have rotten
    int count = 0;
    //Total oranges present in the grid (fresh+rotten)
    int total_oranges = 0;
        
    int m  = grid.size();
    int n = grid[0].size();
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1 || grid[i][j] == 2) total_oranges++;
            //If oranges are rotten push their co-ordinates into the Q
            if(grid[i][j] == 2){
              q.push({i,j});
            }
        }
    }
    //If there is no orange present
   if(total_oranges == 0) return 0;
    //When there is no rotten orange present in the grid
    if(q.size() == 0) return -1;
    //We have to check in 4 directions of a rotten orange
         /*
             1          2 
           1 2 1 ---> 2 2 2
             1          2
         */
    //Therefore we will add these co-ordinates one by one to the current rotten orange's co-ordinates.
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
        
    while(!q.empty()){
        int k = q.size();
        //Add the current count of rotten oranges. That are present in the Q.
        count+=k;
        //BreadthFirstSearch
        while(k--){
            vector<int> curr = q.front();
            q.pop();
            int x = curr[0];
            int y = curr[1];
            //Check in all 4 directions
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||nx>=m||ny<0||ny>=n||grid[nx][ny]!=1) continue;
                //If we have rotten an orange , lets add it to our Q.
                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        //If there are still rotten oranges present in the Q, that means we need another minute to rot them, 
        if(!q.empty()) total_time_taken++;
        
    }
    //Compare the count(the oranges that we rot) to the original oranges number 
    return count == total_oranges?total_time_taken:-1;
    }

int main (){
    vector<vector<int>>grid = {{0}};
    int ans = orangesRotting(grid);
    cout<<ans<<endl;
    return 0;
}