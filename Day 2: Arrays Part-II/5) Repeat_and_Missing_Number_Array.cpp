vector<int> Solution::repeatedNumber(const vector<int> & arr) {
	int xorVal=arr[0],n=arr.size();
        
        for(int i=1;i<n;i++){
            xorVal = xorVal^ arr[i];
         }
         
        for(int i=1;i<=n;i++){
            xorVal = xorVal^ (i);
        }
        
        //in xorVal = xor of duplicate and missing numbers
        //we are segregating all numbers on the basis of the set bit and non set bit
        
        int x=0,y=0,rightSetBit;
        rightSetBit = xorVal & ~(xorVal-1);
        
        for(int i=0;i<n;i++){
            if(rightSetBit & arr[i])
                x=x^ arr[i];
            else
                y=y ^ arr[i];
            
        }
        
        //xoring again from 1 to n 
        for(int i=1;i<=n;i++){
            if(rightSetBit & i )
                x=x^ i;
            else
                y=y ^ i;
        }
        //to check which is duplicate and which is missing => traverse the array and find 
        bool flag = 0;
        vector<int> ans(2);
        for(int i=0;i<n;i++){
            if(x==arr[i]){
                ans[0]=x;
                flag=1;
                break;
            }
        }
        if(flag)
            ans[1]=y;
        else{
            ans[0]=y;
            ans[1]=x;
        }
        return ans;
	// Write your code here 
}
