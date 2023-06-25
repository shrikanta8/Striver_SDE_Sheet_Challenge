vector<int> Solution::dNums(vector<int> &A, int B) {
    int n= A.size();

    if(n<B) 
        return vector<int>();

    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<B;i++){
        mp[A[i]]++;
    }
    ans.push_back(mp.size());
    for(int i=B;i<n;i++){
        mp[A[i-B]]--;
        if( mp[A[i-B]] ==0) //it's count is zero so remove it from map
            mp.erase(A[i-B] );
        mp[A[i]]++;
        ans.push_back(mp.size());
        
    }
    return ans;
}
