vector<int> stringMatch(string &str, string &pat) {
    int l1 = str.length(),l2 = pat.length();
    int q = 128;
    int x=11;        //base here
    int x_m = 1;    //x^(m-1) used for next hash computation
    int hash_p =0, hash_te=0;
    
//hash_new = (old_hash - ((first value of hash) * x^(l2-1) ) ) x + (new value of hash)
    vector<int> ans;
    for(int i=0;i<l2-1;i++)    //x_m = x^(l2-1)
        x_m = ( x_m * x ) % q;
    
    
    for(int i=0;i<l2;i++){
        hash_p = (hash_p*x + pat[i]) % q;    //hash value of pattern
        hash_te = (hash_te*x + str[i]) % q;   //hash value of first window
    }
    
    //start updating
    
    for(int i=0;i<l1-l2+1;i++){
        
        if(hash_p == hash_te){    //possible match is there
            //character by character matching
            bool found=true;
            for(int j=0;j<l2;j++){
                
                if(pat[j] != str[i+j ]){
                    found = false;
                    break;
                }
            }
            if(found)
                ans.push_back(i);
        }
        
        //hash_new = (old_hash - (first_value_of_hash * (x^(l2-1)) ) ) x + (new value of hash)
        //finding new hash
         hash_te = ( (hash_te - (str[i] * x_m) ) * x + str[i+l2] ) % q;
         //as x_m is large quantity hash_te can be -ve
        if(hash_te < 0)
            hash_te += q;
        
    }
    return ans;
    // Write your code here
}
