class Solution {
public:
    
    void calc(int index, vector<int>& nums, vector<vector<int>>& ans, int n){
        if(index ==n){
            ans.push_back(nums);
            return; 
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            calc(index+1,nums,ans,n);
            swap(nums[i],nums[index]);
        }
        return;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        calc(0,nums,ans,n);
        return ans;
    }
};
