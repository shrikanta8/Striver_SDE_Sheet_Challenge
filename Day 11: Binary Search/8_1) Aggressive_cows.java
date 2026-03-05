class Solution {
    public boolean aggressiveCowsHelper(int[] stalls, int mid, int k){
        int val=stalls[0],count=1;
        
        for(int stall:stalls){
            if(stall-val>=mid){
                count++;
                val=stall;
            }
            
        }
        return count>=k;
    }
    public int aggressiveCows(int[] stalls, int k) {
        // code here
        Arrays.sort(stalls);
        
        int n=stalls.length, start=1,end=stalls[n-1]-stalls[0];
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(aggressiveCowsHelper(stalls, mid,k)){
                
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return end;
        
    }
}
