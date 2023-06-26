class Solution {
public:
    bool func(int node, vector<vector<int>>& graph, vector<int>& color){
        for(auto n:graph[node]){
            if(color[n]==-1){
                color[n] = !color[node];
                if(!func(n,graph,color)) return false;
            }
            else if(color[n] == color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(!func(i,graph,color))
                    return false;
            }
                
        }
        return true;
    }
};


//Time Complexity: O(V + E)
    it is a DFS implementation

//Space Complexity: O(V), 
    because, apart from the graph, we maintain a color array.
