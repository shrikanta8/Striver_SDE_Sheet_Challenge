int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,n=nums.size(),maxVal=1;
        // any subarray will have the first element in it or the last element present
        // edge case is for element 0
        
        for(int i=0;i<n;i++){
            maxVal *= nums[i];
            
            if(maxVal == 0){
                maxVal=1;
            }
           
        }
        maxVal=1;
        for(int i=n-1;i >= 0;i--){
            maxVal *= nums[i];
            
            if(maxVal == 0){
                maxVal=1;
            }
            ans= max(ans,maxVal);
        }
        return ans;
    }
