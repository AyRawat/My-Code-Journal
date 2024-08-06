    int solve( int W, int wt[], int val[], int n){
        
        if(W==0 || n <0) return 0;
        
        if(n==0 && wt[n]<=W) return val[0];
        
        int notTake = solve(W,wt, val,n-1);
        int take =INT_MIN;
        if(W >= wt[n]){
            take = val[n] + solve(W-wt[n],wt, val,n-1);
        }
        return max(take, notTake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
       //If there is no weight
       for(int i=wt[0];i<=W;i++) dp[0][i] = val[0];
       
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
               int notTake = dp[i-1][j];
               int take = INT_MIN;
               if(wt[i] <= j){
                   take = val[i] + dp[i-1][j-wt[i]];
               }
               dp[i][j] = max(take, notTake);
           }
       }
       return dp[n-1][W];
    }
