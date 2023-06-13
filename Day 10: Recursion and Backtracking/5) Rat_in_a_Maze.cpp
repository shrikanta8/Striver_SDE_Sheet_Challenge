void findPath(vector<vector<int>> &arr, int n, int x, int y, vector<string>& totAns,string ans, vector<int>& dd){
        
        if(arr[x][y]==0)
            return;
        if(x== n-1 && y==n-1){
            totAns.push_back(ans);
            return;
        }
        
        string dire ="RDLU";
        arr[x][y] =0;
        for(int i=0;i<4;i++){
            
            int newX= x+dd[i];
            int newY = y+dd[i+1];
            
            if(newX >=0 && newY >= 0 && newX<n && newY<n  && arr[newX][newY] ){
                findPath(arr, n, newX, newY, totAns, ans+dire[i],dd);
            }
        }
        arr[x][y] =1;
        
    }
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        vector<string> totAns;
        string ans="";
        vector<int> dd = {0, 1, 0, -1, 0};
        findPath(arr, n, 0, 0, totAns, ans,dd );
            
        return totAns;
        // Your code goes here
    }5
