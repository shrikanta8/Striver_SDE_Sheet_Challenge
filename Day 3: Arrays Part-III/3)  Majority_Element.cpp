class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,ele;
        for(auto n:nums){
            if(c==0){
                ele=n;
            }
            if(ele==n)
                c++;
            else
                c--;
        }
        return ele;
    }
};
