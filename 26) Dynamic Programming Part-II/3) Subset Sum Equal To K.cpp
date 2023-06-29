class Solution {
public:
    bool canPartitionHelper(vector<int>& nums, int sum,int ind, vector<vector<int> >& dp){
        if(sum==0)
            return true;
        if(ind < 0 )
            return false;
        if(dp[ind][sum] !=-1)
            return dp[ind][sum];
        bool notTake = canPartitionHelper(nums,sum,ind-1,dp);
        bool take=false;
        
        if(sum >= nums[ind])
            take = canPartitionHelper(nums,sum-nums[ind],ind-1,dp);
        return dp[ind][sum] =take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto n:nums)
            sum+=n;
        if(sum%2)
            return false;
        vector<vector<int> > dp(nums.size(), vector<int>(sum/2 + 1,-1));
        return canPartitionHelper(nums,sum/2,nums.size()-1, dp);
    }
};
