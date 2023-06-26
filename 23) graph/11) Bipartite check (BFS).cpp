//bipartite graph: that can be coloured using 2 colors such that no two adjacent nodes have same color


class Solution {
public:
    bool func(vector<int>& color ,vector<vector<int>>& edge, int v){
        queue<int> q;
        q.push(v);     //just assuming this node as starting
        color[v]=1;
        
        while(q.size()){
            int f = q.front();
            q.pop();
            for(auto n : edge[f]){
                if(color[n] ==-1){     //if node is not coloured
                     q.push(n);
                     color[n]= !color[f];    //color it with opposite color
                }
                else if(color[n]==color[f]){     //got same color in adjacent nodes
                    return false;
                }
                
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& edge) {
        
        int n=edge.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1)
                if(func(color, edge,i)==false) return false;
        }
        
        return true;
    }
};

//TC: O(N+E) 
    using BFS algo
    
//SC: O(N+E) + O(N) + O(N)
    using adjacency list, color vector,queue
