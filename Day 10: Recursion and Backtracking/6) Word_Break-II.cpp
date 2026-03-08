class Solution {
public:
    unordered_map<string,vector<string> > dp;   //string and all it's answers when called on next
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(dp.find(s) != dp.end())
           return dp[s];
        
        vector<string> result;
        
        for(auto str:wordDict){
            
            if(str == s.substr(0,str.length()) ){
                
                if(str.length() == s.length() ){    //end of the s string when we take it completly
                    result.push_back(str);
                }
                else{
                    vector<string> temp = wordBreak( s.substr(str.length()), wordDict);
                     
                    for(auto ss : temp){
                        result.push_back(str + " "+ ss);
                    }
                    //result will have values
                    //str + temp[0]
                    //str + temp[1]...
                    //result is our new ans
                }
            }
            
        }
        return dp[s] = result;
    }
};



//other soln
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> st;

        for(string& ele:wordDict){
            st.insert(ele);
        }
        vector<int> dp(n+1);
        string str;
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            str="";
            for(int j=i;j<n;j++){
                str+=s[j];
                if(st.find(str)!=st.end() && dp[j+1]){
                    dp[i]=true;
                    break;
                }
            }
            
        }
        return dp[0];
    }
};
