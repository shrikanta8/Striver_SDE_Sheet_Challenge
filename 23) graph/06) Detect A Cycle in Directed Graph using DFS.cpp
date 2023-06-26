class Solution {
public:
    bool func(int node, vector<int> e[], vector<int>& visit,vector<int>& dfsVisit) {
        dfsVisit[node]=1;   //checkig for dfs visit
        visit[node]=1;
        for(auto num: e[node]){
            
            if(visit[num]==0){ 
                if(func(num,e,visit,dfsVisit))  
                    return true;
            }
            else if(dfsVisit[num])      //dfs visit is not over, it means there is a cycle
                return true; 
        }
        dfsVisit[node] = 0;     //dfs visit is over
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> e[n];
        for(auto num:p){
            e[num[1]].push_back(num[0]);
        }
        vector<int> visit(n,0),dfsVisit(n,0);
        for(int i=0;i<n;i++){
            if(!visit[i])
                if(func(i,e,visit, dfsVisit))  return false;
        }
        return true;
        
    }
};

//Time Complexity: O(V + E)

//Space Complexity: O(V)
