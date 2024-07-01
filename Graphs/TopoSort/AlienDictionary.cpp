//https://www.geeksforgeeks.org/problems/alien-dictionary/1
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

    vector<int> topoSort(int V, vector<vector<int>> adj){
        vector<int> indeg(V,0);
        vector<int> result;
        for(int i=0;i<adj.size();i++){
            for(auto it: adj[i]){
             indeg[it]++  ;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for(auto it: adj[curr]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return result;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> graph(K);
        for(int i=0; i< N - 1;i++){
            string first = dict[i];
            string second = dict[i+1];
            int len = min(first.size(), second.size());
            for(int k=0;k<len; k++){
                if(first[k] != second[k]){
                    int position = first[k] - 'a' ;
                     graph[position].push_back(second[k] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K, graph);
        string ans = "";
        for(auto it: topo){
            ans += char(it + 'a');
        }
        
        return ans;
    }
};


int main(){
  return 0;
}
