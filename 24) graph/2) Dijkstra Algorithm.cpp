//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#

class Solution
{
  typedef pair<int, int> p;
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector <int> dis(V,INT_MAX);
        dis[S]=0;   //source node =S
        priority_queue<p, vector<p>,greater<p> > pq;  //min queue
        
        pq.push({0,S}); //starting from this source node
        
        while(pq.size()){
            auto f =pq.top();
            int node = f.second;
            int d = f.first;
            pq.pop();
            
            for(auto num: adj[node]){
                int w = num[1]; //weight
                int nextNode = num[0];    
                if( dis[node] + w < dis[nextNode] ){
                    dis[nextNode]= dis[node] + w;
                    pq.push({dis[nextNode], nextNode });    //pushing only if the distance is less
                }
            }
        }
        return dis;
        // Code here
    }
};


Time Complexity: O((N+E)*logN). Going through N nodes and E edges and log N for priority queue

Space Complexity: O(N). Distance array and priority queue
