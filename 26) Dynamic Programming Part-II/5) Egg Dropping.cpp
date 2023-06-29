 //https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1 

dp[201][201];
    int eggDropHelper(int n, int floor) {
        if(n==1)
            return floor;   //worst case we will need eggs of floor size
      
        if(floor <= 1)
            return floor;   
      
        if(dp[n][floor]!=-1)
            return dp[n][floor];
            
        int ans = INT_MAX;
      
        for(int k=1;k<=floor;k++){
            int notBroke = eggDropHelper(n-1, floor-k);   // floor-k will be the top floors where we have to check
            int broke = eggDropHelper(n, k-1);            // if egg breaks at kth floor we have to check in down side floors
            
            ans =  min(ans, 1 + max(notBroke, broke) );   //taking max for getting the worst case answer
                                                          //min outside to get min values from all the max (worst case) answers!
            
        }
        return dp[n][floor] = ans;
        
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int floor) 
    {
        memset(dp,-1, sizeof(dp));
        return eggDropHelper(n,floor);
        // your code here
    }
