int Solution::solve(vector<int> &A, int k) 
{
    
    unordered_map<int,int> mp;
    
    int c=0,xorVal = 0;
    
    for(auto num:A){
        
        xorVal ^= num;
        
        if(xorVal == k){
            c++;
        }
        if(mp.find(xorVal^k) != mp.end()){  
            c+=mp[xorVal^k];
        }
        mp[xorVal]++;
    }
    return c;
}
