vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n= A.size();

    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());

    set<pair<int, int> > st;    //can't use unordered_set for pairs
    priority_queue<pair<int,pair<int,int> > > pq;

    vector<int> ans;
    
    //{sum,{x,y}}
    pq.push({A[0]+B[0],{0,0}});//first max value

    while(C--){
        auto f = pq.top();
        pq.pop();

        int x=f.second.first, y=f.second.second;

        ans.push_back(f.first);

        //for A[x+1][y] value
        if(x+1<n && st.find({x+1,y}) == st.end()){
            pq.push({A[x+1] +B[y], {x+1,y}});
            st.insert({x+1,y});     //priority queue should have unique pairs
        }

        //for A[x][y+1] value
        if(y+1<n && st.find({x,y+1}) == st.end()){
            pq.push({A[x] + B[y+1],{x,y+1}});
            st.insert({x,y+1}); 
        }
        
    }
    return ans;
}
