int lengthOfLIS(vector<int>& nums) {
    int n= nums.size(),maxVal=INT_MIN,ans=1;
    vector<int> dp(n,1);
    
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){    //traversing till front to find the element which is less than current val and has max dp[] value
            
            if(nums[j]<nums[i]){
                
                maxVal = dp[j]+1;
                dp[i] = max(maxVal,dp[i]);  //add the value +1 which is maximum
                ans= max(ans,dp[i]);
            }
            
        }
    }
    return ans;
}
