class Solution {
public:
    void func(vector<vector<int>>& ans,vector<int>& arr, vector<int>& c, int t,int ind,int  n){
        if(ind==n || t<0) return;
        
        if(t==0){
            ans.push_back(arr);
            return;
        }
        
        arr.push_back(c[ind]);
        func(ans,arr,c,t-c[ind],ind,n);
        arr.pop_back();
    
        func(ans,arr,c,t,ind+1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> arr;
        func(ans,arr, c,t,0 ,c.size());
        return ans;
    }
};
