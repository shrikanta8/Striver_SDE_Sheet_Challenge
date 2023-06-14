class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end =nums.size()-1;
        
        while(start<=end){
            
            int mid = (start+end)>>1;
            
            if(nums[mid] == target)
                return mid;
            
            //left side is sorted
            if(nums[mid]>= nums[start]){
                //figure out if element lies on left half or not
                if(target >=  nums[start] && target <= nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            //right side is sorted
            else{
                if(target <=  nums[end] && target >= nums[mid])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }
};
