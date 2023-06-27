class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<bool> MST(V,0);
        vector<int> weight(V,INT_MAX), parent(V,-1);
        weight[0]=0;
        parent[0] = -1;
        for(int i=1;i<V;i++){
            int minNode,minWeight = INT_MAX;
            
            for(int j=0;j<V;j++){
                if( !MST[j] && minWeight > weight[j]){
                    minWeight = weight[j];
                    minNode =j;
                }
            }
            MST[minNode] = 1;
            
            for(auto s:adj[minNode]){
                if(!MST[s[0]] && weight[s[0]] > s[1]){
                    weight[s[0]] = s[1];
                    parent[s[0]] = minNode;
                }
            }
            
        }
        int sum=0;
            return accumulate(weight.begin(),weight.end(), sum);
        // code here
    }
};


Time Complexity: O(N^2)
    Going through N Node for N-1 times

Space Complexity: O(N)
     3 arrays of size N
