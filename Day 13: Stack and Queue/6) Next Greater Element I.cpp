class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        
        for(int n:nums2){       //finding next greater element 
            while(st.size() && st.top() < n){
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i]) != mp.end())
                nums1[i] = mp[nums1[i]];
            else
                nums1[i] = -1;
        }
        return nums1;
    }
};
