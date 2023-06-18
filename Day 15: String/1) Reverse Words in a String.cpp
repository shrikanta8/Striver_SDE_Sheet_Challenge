class Solution {
public:
    string reverseWords(string s) {
        
        string ans="",res="";
        int i=0,n=s.length();
        
        while(i<n){
            while(i<n && s[i] ==' ')
                i++;
            if(i>=n)
                break;
            
            while(i<n && s[i]!=' ')
                res+=s[i++];
            
            if(ans=="")
                ans=res;
            else
                ans =res + " " + ans;
            
            res="";
        }
        return ans;
        
    }
};
