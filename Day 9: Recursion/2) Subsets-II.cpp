class Solution {
public:  
    void func(vector<int>& nums, vector<vector<int>>& ans,int ind, vector<int> a,int n){
        ans.push_back(a);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1] ) 
                continue;
            a.push_back(nums[i]);
            func(nums,ans, i+1,a,n);
            a.pop_back();
        }
        
    }
   vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> a;
       sort(nums.begin(), nums.end());
        func(nums,ans,0,a,nums.size());
       
        return ans;
    }
};
