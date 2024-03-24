#include<bits/stdc++.h>
using namespace std;

int minPath(vectro<vector<int>> heights){
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> paths(m,vector<int>(n, INT_MAX)); // Initialize paths with INT_MAX
        paths[0][0] = 0;
        
        priority_queue<pq_type, vector<pq_type>, greater<pq_type>> pq;
        pq.push({0, {0,0}});
        
        vector<int> rows = {0, 1, -1, 0};
        vector<int> cols = {-1, 0, 0, 1};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int x = curr.second.first;
            int y = curr.second.second;
            int d = curr.first;
            
            // If already visited with lower effort, continue
            if (d > paths[x][y]) continue;
            
            if (x == m - 1 && y == n - 1) return paths[x][y];
            
            for (int i = 0; i < 4; i++) {
                int newR = rows[i] + x;
                int newC = cols[i] + y;
                
                if (newR >= 0 && newR < m && newC >= 0 && newC < n) {
                    int curr_effort = abs(heights[x][y] - heights[newR][newC]);
                    int new_effort = max(curr_effort, d);
                    
                    // If the new effort is less than the current effort to reach (newR, newC)
                    // Update the path and push it into the priority queue
                    if (new_effort < paths[newR][newC]) {
                        paths[newR][newC] = new_effort;
                        pq.push({new_effort, {newR, newC}});
                    }
                }
            }
        }
        
        return -1; // No path found
}

int main(){
  return 0;
}
