vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        int maxDeadline = INT_MIN;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        int ans=0,jobs=0;
        
        vector<int> chk(maxDeadline+1,-1);
        for(int i=0;i<n;i++){
            
            int deadline = arr[i].dead;
            
            while(deadline > 0 && chk[deadline] != -1){
                deadline--;
            }
            if(deadline > 0 && chk[deadline] == -1){
                chk[deadline]=1;
                ans += arr[i].profit;
                jobs++;
            }
    
        }
        return vector<int> {jobs,ans};
        // your code here
    }  
