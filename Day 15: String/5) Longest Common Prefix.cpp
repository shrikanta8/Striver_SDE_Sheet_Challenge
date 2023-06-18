//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& A) {

        int n=A.size(),i;
        string s="";
        if(n==0 )
            return "";
        if(n==1)    //that will be only the max prefix
            return A[0];
        
        int n1=A[0].length();

        for(int j=0;j<n1; j++){ //traversing to all characters of first word
            
            char c =A[0][j];
            
            for( i=1;i<n;i++){ //traversing and checking in all the rows 
                
                if( A[i].length()<=j || c != A[i][j] )
                    return A[0].substr(0,j);    //values from 0 till current-1 will be in our answer
                
            }
            if(i==n)
                s += c; //case where all words are equall
        }
        return s;
    
    }
};
