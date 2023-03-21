#include<bits/stdc++.h>
using namespace std;

   vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> result;

     queue<pair<int , vector<int> > > q;
     vector<bool> visited(V, false);
     q.push({0, adj[0]});
     visited[0] = true;
     result.push_back(0);
     while(!q.empty()){
         int qSize = q.size();
         for(int i=0;i<qSize;i++){
             pair<int, vector<int> > p = q.front();
             q.pop();
             for(int x:p.second){
                 if(!visited[x]){
                     result.push_back(x);
                     visited[x] = true;
                     q.push({x , adj[x]});
                 }
             }
         }
     }
     
        return result;
    }

int main(){

    return 0;
}