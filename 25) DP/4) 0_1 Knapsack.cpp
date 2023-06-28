//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1/#

  int func(int W, int wt[], int val[], int ind, vector<vector<int> >& dp){
        if(ind == 0 ){
            if(wt[0] <= W) return val[ind];
            return 0;
        }
        if(dp[ind][W]!=-1)
            return dp[ind][W];
            
        int notTake =  func(W,wt,val,ind-1, dp);
        int take = INT_MIN;
        
        if(wt[ind] <= W){
            take = val[ind] + func(W-wt[ind],wt,val,ind-1, dp);
        }
        return dp[ind][W] = max(take,notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int> > dp(n,vector<int>(W+1,-1));
        
        return func(W,wt,val,n-1,dp);
       // Your code here
    }
