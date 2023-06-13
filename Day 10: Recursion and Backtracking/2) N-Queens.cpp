class Solution {
public:
    
    void func(int col, int n, vector<vector<string>>& ds, vector<string>& ans, vector<bool>& leftRow,vector<bool>& bottDiag, vector<bool>& topDiag){
        if(col==n){
            ds.emplace_back(ans);
            return;
        }
        for(int r=0;r<n;r++){
            if(!leftRow[r] && !bottDiag[r+col] && !topDiag[(n-1) + (col-r)] ){
                
                leftRow[r]=1;
                bottDiag[r+col]=1;
                topDiag[(n-1) + (col-r)]=1;
                
                ans[r][col] ='Q';
                func(col+1,n,ds,ans,leftRow, bottDiag, topDiag);
                ans[r][col] ='.';
                
                leftRow[r]=0;
                bottDiag[r+col]=0;
                topDiag[(n-1) + (col-r)]=0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ds;
        vector<string> ans(n);
        string s(n,'.'); 
        vector<bool> leftRow(n+1,0),bottDiag(2*n-1,0),topDiag(2*n-1,0);
        for(int i=0;i<n;i++){
            ans[i]=s;
        }
        func(0,n,ds,ans,leftRow, bottDiag, topDiag);
        return ds;
    }
};
