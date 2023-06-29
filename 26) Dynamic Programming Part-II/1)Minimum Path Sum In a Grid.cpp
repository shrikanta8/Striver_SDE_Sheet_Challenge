class Solution {
public:
    int minPathSum(vector<vector<int>>& grid,int x=0,int y=0) {
        int r=grid.size(),c = grid[0].size();
        int dp[r][c];
        dp[0][0]=grid[0][0];
        for(int i=1;i<c;i++ )
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for(int i=1;i<r;i++ )
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1;i<r;i++ ){
            for(int j=1;j<c;j++ ){
                dp[i][j] = grid[i][j] + min(dp[i][j-1],dp[i-1][j]  );
            }
        }
        return dp[r-1][c-1];
    }
};
