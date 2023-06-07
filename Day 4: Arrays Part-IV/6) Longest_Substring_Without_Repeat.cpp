class Solution {
public:
    int lengthOfLongestSubstring(string A) {
        unordered_map<char,int> mp;
        int n=A.length();
        
        int ans=0,start=0;
        for(int i=0;i<A.length();i++){
            if(mp.find(A[i]) != mp.end() && mp[A[i]]>=start){

                
                start=mp[A[i]]+1;
            }
            ans = max(ans,i-start+1);
            mp[A[i]]=i;
        }
        return ans; 
    }
};

//mp[A[i]]>=start 
//testcase abba
