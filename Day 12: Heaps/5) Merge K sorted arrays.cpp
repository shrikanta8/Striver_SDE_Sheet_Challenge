#include<bits/stdc++.h>

typedef pair<int,pair<int,int> > pp;

vector<int> mergeKSortedArrays(vector<vector<int>>&A, int row)
{
    priority_queue<pp,vector<pp>,greater<pp> > pq;
    int col=A[0].size();
    
    //inserting all first column values in pq
    for(int i=0;i<row;i++){
        pq.push({A[i][0],{i,0}});
    }
    vector<int> ans;
    
    while(!pq.empty()){

        auto &f = pq.top();
        int val = f.first;
        int r = f.second.first, c = f.second.second;
        c++;//column +1
        pq.pop();
        ans.push_back(val);

        //if c is in our range of column then only we will add it in pq
        if(c<A[r].size())
            pq.push({A[r][c],{r,c}});
        
    }
    return ans;
    // Write your code here. 
}
