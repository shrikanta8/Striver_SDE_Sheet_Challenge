class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1,0),s(amount+1);
        
        int n = coins.size();
        
        for(int T=0;T<=amount; T++){
            
            if(T % coins[0] == 0)
                f[T] = T/coins[0];  
            else
                f[T]= 1e9;
            
        }
        
        for(int ind = 1; ind<n;ind++){
            for(int T=0;T<=amount; T++){
                int take = INT_MAX;
                
                int notTake = f[T];
                
                if(coins[ind] <= T){
                    take = 1 + s[T-coins[ind]]; 
                }
                s[T] = min(take,notTake);
            }
            f=s;
        }
        
        int ans=f[amount];
        if(ans>=1e9) return -1;
        return ans;
    }
    
};
