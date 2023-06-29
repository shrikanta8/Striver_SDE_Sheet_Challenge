//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

static bool comp(Job a, Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        
        int maxDeadline = INT_MIN;
        
        for(int i=0;i<n;i++){   //finding max deadline
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        
        int ans=0,jobs=0;
        
        vector<int> chk(maxDeadline+1,-1);
        
        for(int i=0;i<n;i++){
            
            int deadline = arr[i].dead;
            
            //finding the empty place (-1) from our deadline till 1
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



//TC: O(n log n) + O(n*m)
  
//m is max deadline
