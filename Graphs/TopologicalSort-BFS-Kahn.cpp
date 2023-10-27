#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> indeg(V,0);
    vector<int> result;
    queue<int> q;
    //Fill the indeg arr
   for(int i=0;i<V;i++){
       for(auto it: adj[i]){
           indeg[it]++;
       }
   }
    for(int i=0;i<indeg.size();i++){
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int curr_ele = q.front();
        q.pop();
        result.push_back(curr_ele);
        for(auto it: adj[curr_ele]){
            indeg[it]--;
            if(indeg[it] == 0) q.push(it);
        }
    }
   return result;
}