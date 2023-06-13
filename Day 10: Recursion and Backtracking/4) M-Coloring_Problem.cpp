// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node, bool graph[101][101], int n, vector<int>& color, int currentColor){
    for(int i=0;i<n;i++){
        if(node != i && graph[node][i]==1 && color[i]==currentColor)
            return false;
    }
    return true;
}

bool isPossible(int node, bool graph[101][101], int m, int n, vector<int>& color){
    if(node == n)
        return true;
        
    for(int col=1; col<=m; col++){
        if(isSafe(node, graph, n, color, col)){
            color[node]= col;   //
            
            if(isPossible(node+1, graph, m, n, color))
                return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n);
    return isPossible(0, graph, m, n, color);
    // your code here
}
