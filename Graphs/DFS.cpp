void dfs(int V, vector<int> adj[] , vector<int> &visited , vector<int> &ls){
        if(!visited[V]){
            visited[V] = 1;
            ls.push_back(V);
         for(auto it : adj[V]){
            if(!visited[it]){
                dfs(it, adj,visited,ls);
            }
        }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V);
        vector<int> result;
        
        dfs(0, adj,visited, result);
        return result;
        
    }