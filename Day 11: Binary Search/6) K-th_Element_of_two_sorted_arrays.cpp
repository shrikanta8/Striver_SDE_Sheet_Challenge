class Solution{
    public:

    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        //first array shoud be less in size
        if(n > m) {
            return kthElement(arr2, arr1, m, n, k); 
        }
        
        //if(k>m) them low can't be 0
        //if(k < n) at max we can at max take k elements NOT n
        int low = max(0,k-m), high = min(k,n);
            
        while(low <= high) {
            int cut1 = (low + high) >> 1; 
            int cut2 = k - cut1; 
            
             //at start if cut is there then we will take INT_MIN
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            
            //at end if cut is there then we will take INT_MAX
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];  
            int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
                
                //valid
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) { 
                high = cut1 - 1;    //move to left side
            }
            else {
                low = cut1 + 1;     //move to right side
            }
        }
        return 1; 

    }
};
