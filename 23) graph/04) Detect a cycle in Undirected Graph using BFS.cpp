//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
public:
  bool func(int V, vector<int> adj[], vector<bool>& visit){
      queue<pair<int,int> > q;
      q.push({V,-1});   //<node_val, parent>
      visit[V] =1;
      while(q.size()){
          int node = q.front().first,par= q.front().second;
          q.pop();
          for(auto num : adj[node]){

                if(!visit[num]){
                    q.push({num,node});
                      visit[num] =1;
                }
                else if(num!=par )    //if num == par => (neighbour and parent are same) then it won't be a cycle
                    return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visit(V+1,0);
        for(int i=1;i<=V;i++){
            if(!visit[i] )
                if( func(i,adj,visit) ) return true;
        }
        return false;
        // Code here
    }
  };
  
  //Time Complexity: O(N+E)

  //Space Complexity: O(N+E) +  O(N) + O(N) , space for adjacent list , array and queue
