//Maximum Subarray Sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=nums[0],n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {   
            sum+=nums[i];
            
            if(sum>max)
                max=sum;
            if(sum<0)
            sum=0;
        }
        return max;
    }
};
