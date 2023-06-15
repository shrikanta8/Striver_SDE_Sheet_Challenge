class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n =nums.size();
        
        vector<vector<int> > v(n+1);  
        //n+1 because if there is only one element in whole array then that number will be stored in index n
        
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(int n : nums){
            mp[n]++;
        }
        
        for(auto m:mp){
            v[m.second].push_back(m.first);
        }
        
        for(int i=n;i>=0 && ans.size()<k;i--){
            if(!v[i].empty()){
                ans.insert(ans.end(),v[i].begin(),v[i].end());//write end or begin anything!       
                //since answer is always unique so ther's no need to keep track of k
            }
        }
        return ans;   
    }
};
