class Solution {
public:
    int minOperations(string& word1, string& word2, int i, int j, vector<vector<int> >& dp){
        
        if(i<0){    //return the remaining word2 letters, operations can be insertion of j+1 letters in word1
            return j+1;
        }
        if(j<0)     //return the remaining word1 letters, operations can be deletion of i+1 letters of word1
            return i+1;
            
        if(dp[i][j] !=-1)
            return dp[i][j];
        
        if(word1[i] == word2[j]){   //no operation required here
            return dp[i][j] = 0 + minOperations(word1, word2, i-1, j-1, dp);
        }
        //not equal then
        return dp[i][j] = 1 + min( minOperations(word1, word2, i-1, j-1, dp), min( minOperations(word1, word2, i, j-1, dp), minOperations(word1, word2, i-1, j, dp)  ) );
        
        // i-1, j-1 REPLACE
        // i, j-1 INSERT
        // i-1, j DELETE
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.length(),len2 = word2.length();
        
        vector<vector<int> > dp(len1,vector<int>(len2,-1));
        return minOperations(word1, word2, len1-1,len2-1,dp);
        
    }
};

Time Complexity: O(N*M)

Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.

Space Complexity: O(N*M) + O(N+M)

Reason: We are using a recursion stack space(O(N+M)) and a 2D array ( O(N*M)).
