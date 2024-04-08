	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int m = matrix.size();
	    vector<vector<int>> adj = matrix;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j] == -1) adj[i][j] = 1e9;
	            if(i == j) adj[i][j] = 0;
	        }}
	    for(int k=0;k<m;k++){
	        for(int i=0;i<m;i++){
	            for(int j=0;j<m;j++){
	                adj[i][j] = min(adj[i][j] ,adj[i][k] + adj[k][j]);
	                
	            }
	        }
	    }
	    for(int i=0;i<m;i++){
	        for(int j=0;j<m;j++){
	            if(adj[i][j] == 1e9) adj[i][j] = -1;
	        }
	    }
	}
