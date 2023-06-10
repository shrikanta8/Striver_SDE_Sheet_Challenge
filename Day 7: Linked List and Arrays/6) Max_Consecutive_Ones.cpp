class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,ans=0;
        for(auto ele:nums){
            if(ele){
                c++;
            }
            else{
                ans=max(c,ans);
                c=0;
            }
        }
        ans=max(c,ans);
        return ans;
    }
};
