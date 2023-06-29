//https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

bool isPalindrome(int i,int j,string str){
        while(i<j){
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int palindromicPartitionHelper(string str, int i, int j, vector<vector<int> > &dp){
        
        if(i>=j)        //one character or no character
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(isPalindrome(i,j,str)==true) //no need to go further since it is the minimum
            return dp[i][j]=0;
        
        int temp = INT_MAX;
        for(int k=i;k<=j-1;k++){        
            int left,right; 
            
            if(dp[i][k] !=-1)
                 left = dp[i][k];
            else
                left = palindromicPartitionHelper(str, i,k, dp);
                
            if(dp[i][k+1] !=-1)
                 right = dp[k+1][j];
            else
                right = palindromicPartitionHelper(str, k+1, j, dp);
                
            int ans= 1 + left + right;
            
            //int ans= 1 + palindromicPartitionHelper(str, i,k, dp)+palindromicPartitionHelper(str, k+1,j, dp);
            //giving tle why??
        
            temp = min(temp,ans);
        }
        return dp[i][j] = temp;
    }
    int palindromicPartition(string str)    
    {
        int n=str.length();
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        return palindromicPartitionHelper(str,0,n-1,dp);
        
        // code here
    }
