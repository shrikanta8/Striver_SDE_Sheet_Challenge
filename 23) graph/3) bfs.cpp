//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

class Solution {
public:
    void func(int V, vector<bool >& visit, vector<int> e[], vector<int>& ans){
        
        queue<int> q;
        q.push(V);
        
        visit[V]=1;
        while(q.size()){
            int f = q.front(); q.pop();
            ans.push_back(f);
            for(auto num: e[f]){
                if(!visit[num]) {
                    q.push(num);
                    visit[num]=1;
                }
            }
        }
        
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
         vector<int> ans;
         vector<bool > visit(V+1,0);
        func(0,visit,adj,ans);
         return ans;
        // Code here
    }
};

//Time Complexity : O(N+E)
  N = Nodes , E = travelling through adjacent nodes

//Space Complexity : O(N+E) + O(N) + O(N) 
  Space for adjacency list, visited array, queue data structure
