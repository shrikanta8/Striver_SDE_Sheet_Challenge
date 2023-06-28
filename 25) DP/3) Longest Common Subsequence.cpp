    
int longestCommonSubsequence(string s, string t) {
    
    int l1= s.length(),l2=t.length();
    
    vector<vector<int>> dp(l1+1, vector<int>(l2+1));    //taking +1 array for keeping 0th length
    
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j]= max( dp[i][j-1],dp[i-1][j]);
            
        }
    }
    
    return dp[l1][l2];
}
