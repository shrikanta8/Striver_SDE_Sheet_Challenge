//don't works for negative cycle!

//it can detect negative cycle

//it works for Directed graph

//for undirected graph we have to convert it to directed graph using bidirected edges


STEPS
I. relax all the edges n-1 times (n=NUMBER OF VERTICES)
    if(dist[u] + wt < dist[v])
        dist[v] = dist[u] + wt
        
II. after relaxing n-1 times, distance array will be shortest possible and we can't have any shortest distance possible after that


==>TO CHECK FOR NEGATIVE CYCLE
    i) perform step I only once
    ii) if distance reduces it means there is a -ve cycle!
    
    
  
class Solution{
public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dis(V,100000000);
        dis[S]=0;
        for(int i=1;i<=V-1;i++){
            for(auto num: adj){
                if( dis[num[0]]+ num[2] < dis[num[1]])
                    dis[num[1]] = dis[num[0]]+ num[2];
            }
        }
        
        //checking for negative cycles
        // for(auto num: adj){
        //     if( dis[num[0]]+ num[2] < dis[num[1]]){
        //         cout<<"cycle is there";
        //         break;
        //     }
        // }
        
        return dis;
        // Code here
    }
};
    
Time Complexity: O( (N-1)*E). We check E edges N-1 times

Space Complexity: O(N). Distance Array
