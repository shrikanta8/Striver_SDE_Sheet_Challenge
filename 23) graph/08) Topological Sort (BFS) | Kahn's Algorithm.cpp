//https://practice.geeksforgeeks.org/problems/topological-sort/1#

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    queue<int> q;
	    vector<int> inDegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	            ++inDegree[it];   
	        }
	        //traverse inDegree 
	    }
	    
	    for(int i=0;i<V;i++){
	        // push vertices having indegree 0 in queue
	        if( !inDegree[i])
	            q.push(i);
	    }
	    while(q.size()){
	        int f = q.front();
	        q.pop();
	        ans.push_back(f);
	        for(auto it: adj[f]){
	           // traversing adjacent nodes and reducing its indegree by 1
	            --inDegree[it];
	            if( !inDegree[it]){
	               // if indegree is 0 push it to queue
	                q.push(it);
	            }
	        }
	    }
	    return ans;
	    // code here
	}
};


Time Complexity: O(N+E)

Space complexity: O(N)+O(N)
