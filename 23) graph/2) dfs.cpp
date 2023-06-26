//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
  
void func(int V, vector<int> adj[], vector<int>& vis, vector<int>& ans){
      ans.push_back(V);
              
      vis[V] = 1;
      for(auto it:adj[V]){
          if(vis[it] == 0){
              func(it ,adj,vis, ans);
          }
          
      }
  }
  
  // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                func(i,adj,vis,ans);
        }
        
        return ans;
        
        // Code here
    }
    
    };
