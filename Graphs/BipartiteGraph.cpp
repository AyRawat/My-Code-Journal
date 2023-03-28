#include<bits/stdc++.h> 
//A few things to Observe
//Any Linear graph can always be Bipartite
// Any Graph with even length cycle will be Bipartite. 
//Any Graph with Odd Length Cycle will be Non Bipartite.


using namespace std;
    bool bfs(int start, vector<vector<int>> & graph ,vector<int> &visited){
         int m = graph.size();
         int n= graph[0].size();
         queue<int> q;
        visited[start] = 0;
        q.push(start);
        while(!q.empty()){
           int node = q.front();
           q.pop();
           for(auto it : graph[node]){
             //If Adjacent Node is not yet colored
             //  give Opp color
             if(visited[it] == -1){
               visited[it] = !visited[node];
                q.push(it);
             }//If the adjacent guy has been colored.
             else if(visited[it] == visited[node]){
               return false;
             }

           }
        }
return true;
    }

bool isBipartite(vector<vector<int>>& graph) {
      int m = graph.size();
      int n= graph[0].size();
      vector<int> visited(m, -1);
        bool answer;
        for(int i=0;i<m;i++){
          if(visited[i] == -1){
            if(!bfs(i, graph,visited)) return false;
          }
        }
        return true;
    }
int main(){
return 0;
}