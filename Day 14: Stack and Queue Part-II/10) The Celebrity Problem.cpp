celebrity(vector<vector<int> >& M, int n) 
    {
        int pr=0,pc=n-1;
        while(pr < pc){
                if(M[pr][pc])
                    pr++;
                else
                    pc--;
        }
        
        for(int i=0;i<n;i++){
                if(i!=pc && (M[pc][i] || M[i][pc]==0) )
                    return -1;
        }
        return pc;
        // code here 
    }
