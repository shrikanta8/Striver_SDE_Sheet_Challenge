//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    
    void func(vector<vector<char>>& grid, int i, int j, int r, int c){
        if(i<0 || j<0 || i>=r || j>= c || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0'; //making it visited and traversing in 4 directions
        func(grid,i+1,j,r,c);
        func(grid,i ,j+1,r,c);
        func(grid,i-1,j,r,c);
        func(grid,i,j-1,r,c);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int r= grid.size(), c= grid[0].size();
        int ans=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){        //if value is 1 then only traverse in 4 directions
                    ans++;      //as we got 1 increment ans
                    func(grid,i,j,r,c);
                }
            }
        }
        return ans;
    }
};
