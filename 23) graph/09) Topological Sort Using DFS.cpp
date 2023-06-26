//https://practice.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
    //without stack
	public:
	int ind;
	void func(int V, vector<int> adj[],vector<bool>& visit,vector<int>& ans, stack<int>& s){
	    visit[V]=1;
	    for(auto num: adj[V]){
	        if(!visit[num]){
	            func(num,adj,visit,ans,s);
	        }
	    }
	   ans[ind--]=V;
	    
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    ind=V-1;
	    vector<bool> visit(V,0);
	    vector<int> ans(V);
	    stack<int> s;
	    for(int i=0;i<V;i++){
	        if(!visit[i]) func(i,adj,visit,ans,s);
	    }
	  
	    return ans;
	    // code here
	}
};



Time Complexity: O(N+E) 

N = Number of node , E = Number of Edges

Space Complexity: O(N) + O(N)

Visited Array and Stack data structure. Both will be using O(N).

Auxiliary Space Complexity:  O(N)

Recursion call of DFS
