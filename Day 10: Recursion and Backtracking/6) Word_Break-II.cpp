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
