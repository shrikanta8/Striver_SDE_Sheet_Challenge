vector<int> Solution::prevSmaller(vector<int> &A) {
    
    int n = A.size();

    vector<int> v(n,-1);
    
    stack<int> s;
    s.push(A[0]);
    
    for(int i=1;i<n;i++){
        
        while(s.size() && s.top() >= A[i])
            s.pop();    //popping all elements greater than A[i]
            
        if( s.size()){
            v[i]=s.top();       //it is lower than A[i];
        }
        s.push(A[i]);
    }
    return v;
}
