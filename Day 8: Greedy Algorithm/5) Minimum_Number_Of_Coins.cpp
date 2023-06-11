int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int> > dp(M+1,vector<int>(V+1));
	    
	    for(int t=1;t<=V;t++){
	        if(t%coins[0] == 0)
	            dp[0][t]= t/coins[0];
	       else
	            dp[0][t] = 1e9;
	    }
	    
	    for(int ind=1;ind<M;ind++){
	        for(int t=1;t<=V;t++){
	            int take=1e9;
	            int notTake = dp[ind-1][t];
	            if(t >= coins[ind]){
	                take = 1+ dp[ind][t-coins[ind]];
	            }
	            dp[ind][t] = min(take,notTake);
	        }
	    }
	    if(dp[M-1][V] == 1e9)
	        return -1;
	    return dp[M-1][V];
	    // Your code goes here
	} 
