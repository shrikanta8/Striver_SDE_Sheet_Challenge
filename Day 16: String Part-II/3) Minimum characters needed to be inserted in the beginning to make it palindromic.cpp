int Solution::solve(string str) {
    int origSize = str.size();
    string A = str;
    reverse(str.begin(),str.end());
    A = A +'#'+ str;
    
    //lps function
    int sz = A.length(), i=1,len=0;
    
    vector<int> lps(sz);
    lps[0] = 0;
    
    while(i < sz){
        
        if(A[i] == A[len]){
            lps[i] = len+1;
            len++;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];   //going to previous substring's letter
            }
            else{
                lps[i]=0; //no matching letter hence increment by 1
                i++;
            }
        }
    }
    
    return origSize - lps[sz-1];
    //lps[sz-1] will have the value which is the largest palindromic string in str;
}

//O(n) tc
