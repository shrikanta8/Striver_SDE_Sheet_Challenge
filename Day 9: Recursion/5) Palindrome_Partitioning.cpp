class Solution {
public:
    bool isPalindrome(string s,int i, int l){
        
        while(i<=l){
            if(s[i++]!=s[l--])
                return false;
        }
        return true;
    } 
    void chk(vector<vector<string>>& ans, string s, int l, int ind, vector<string>& ds){
        if(ind == l){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<l;i++){
                if(isPalindrome(s,ind,i) ){
                    ds.push_back(s.substr(ind,i-ind+1));
                    chk(ans,s,l,i+1,ds);
                    ds.pop_back();
                }
                
        }
    } 
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> ds;
        int l=s.length();
        chk(ans, s,l,0,ds);
        return ans;
    }
};
