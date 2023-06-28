//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

int dp[101][101];
    int matrixMultiplicationHelper(int arr[], int i, int j){
        if(i >= j)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int minVal = INT_MAX;
        dp[i][j] = INT_MAX;
        
        for(int k=i;k<j;k++){
            int ans = matrixMultiplicationHelper(arr,i,k) + matrixMultiplicationHelper(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];    //i-1 bcose it is the left dimension of the matrix on left
            minVal = min(minVal,ans);
           
        }
        return dp[i][j]=minVal;
    
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof dp);
        return matrixMultiplicationHelper(arr,1,N-1);   // starting from 1 bcose arr[0] and arr[1] are dimensions of matrix
        // return dp[1][N-1];  //for case when n=2 ...it will give -1 in place of 0
        // code here
    }
