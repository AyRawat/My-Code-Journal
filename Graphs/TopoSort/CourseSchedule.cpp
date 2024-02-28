#include<bits/stdc++.h>
using namespace std;

 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<int> sortedArr;
        vector<vector<int>> graph(numCourses);
        for(vector<int> req: prerequisites){
          int from = req[0];
          int to = req[1];
          graph[from].push_back(to);
          indeg[to]++;
        }
        queue<int> q;
    
        for (int i = 0; i < indeg.size(); i++) {
            if (indeg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            sortedArr.push_back(curr);
            for (auto it : graph[curr]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (sortedArr.size() < numCourses)
            return false;
        return true;
    }

int main(){
  return 0;
}
