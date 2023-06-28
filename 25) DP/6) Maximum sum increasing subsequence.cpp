//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

int maxSumIS(int nums[], int n)  
{  
   
    int maxVal=INT_MIN,ans=nums[0];
      vector<int> dp(n,0);
      
      
      for(int i=0;i<n;i++){

    dp[i] = nums[i];
          for(int j=i-1;j>=0;j--){
              
              if(nums[j]<nums[i]){
              
                  dp[i] = max(nums[i] + dp[j],dp[i]);
                  ans= max(ans,dp[i]);
              }
              
          }
      }
      return ans;
    // Your code goes here
}
