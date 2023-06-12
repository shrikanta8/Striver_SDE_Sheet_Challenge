class Solution {
public:
    void func(vector<vector<int>>& ans,vector<int>& arr, vector<int>& c, int t,int ind,int  n){
        if( t < 0 ) return;
        
        if(t==0){
            ans.push_back(arr);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i!=ind && c[i]==c[i-1])continue;
            arr.push_back(c[i]);
            func(ans,arr,c,t-c[i],i+1,n);
            arr.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        vector<int> arr;
        func(ans,arr, c,t,0 ,c.size());
        return ans;
    }
};
