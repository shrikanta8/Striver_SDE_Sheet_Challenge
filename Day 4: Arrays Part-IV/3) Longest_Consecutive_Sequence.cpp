class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        for(auto n:nums)
            st.insert(n);
        
        int maxAns=0;
        
        for(auto n:nums){
            
            if(st.find(n-1) == st.end()){  
                //if n-1 is not there in set then start searching for n+1 number and keep increasing the count  
                int count=1,startNum = n;
                
                while( st.find(++startNum) != st.end() )
                    count++;
                
                maxAns = max(maxAns,count);
            }
        }
        return maxAns;
    }
};
