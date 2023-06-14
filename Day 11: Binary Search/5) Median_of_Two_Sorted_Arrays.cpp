class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int size1 = nums1.size(), size2 = nums2.size();
        
        int k = (size1+size2)>>1;
        // int start = max(0,k-size2), end = min(k,size1);
        
        int start=0,end=size1;
        while(start<=end){
            int cut1 = (start + end)>>1;
            int cut2 = k-cut1;  //cut in 2nd array
            
            int l1= (cut1==0)?INT_MIN:nums1[cut1-1] ;
            int l2= (cut2==0)?INT_MIN:nums2[cut2-1];
            int r1= (cut1==size1)?INT_MAX:nums1[cut1];
            int r2 = (cut2==size2)?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((size1+size2)%2==0)
                    return ((double) max(l1,l2) + min(r1,r2))/2.0;
                else
                    return min(r1,r2);
            }
            else if(l1 > r2)
                end = cut1-1;
            else
                start = cut1+1;
        }
        return 0.0;
    }
};
