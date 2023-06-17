class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r= grid.size(),c= grid[0].size();
        int totOra=0;   //total ornges in grid
        int minutes=0;      //answer
        int countOranges=0;     //oranges that we have visited
        
        queue<pair<int,int> > q;    //<i,j>
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j])          //counting number of oranges in grid
                    totOra++;       
                if(grid[i][j] == 2){    //pusing all rotten oranges in queue
                    q.push({i,j});
                    
                }
                    
            }
        }
        if(totOra==0)   //no oranges
            return 0;
        
        vector<int> dd={0,1,0,-1,0};
        
        while(q.size()){
            
            int num = q.size();
            countOranges +=num; //visiting this oranges
            
            minutes++;
            
            while(num--){
                
                auto fr=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    
                    int newR=fr.first + dd[i], newC= fr.second + dd[i+1];
                    
                    if(newR>=0 && newR<r && newC>=0 && newC<c && grid[newR][newC]==1){
                        grid[newR][newC]=2;
                        q.push({newR,newC});
                    }
                }
            }
        }
        if(countOranges == totOra )
            return minutes-1;   //-1 bcose we are  not considering initial rotten oranges
        return -1;
        
    }
};
