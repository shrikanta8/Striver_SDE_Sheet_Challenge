class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n= nums.size(),min1,min2;
        
        for(min1 = n-2;min1>=0;min1--){
            if(nums[min1]<nums[min1+1])
                break;
        }
        if(min1<0){     //5 4 3 2 1 this case=> output will be 1 2 3 4 5
            reverse(nums.begin(), nums.end());
        }
        else{
            for(min2=n-1;min2>min1;min2--){
                if(nums[min2] > nums[min1])
                    break;
            }
            swap(nums[min2], nums[min1]);   //min2 is next greater than min1, hence next greater element will have min2 in place of min1
            reverse(nums.begin() +1+ min1, nums.end());     //making that part of array in ascending order
        }
    }
};
