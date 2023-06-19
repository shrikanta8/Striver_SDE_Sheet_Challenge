//https://practice.geeksforgeeks.org/problems/search-pattern0205/1#

void computeLongestPrefixSuffix(string pat, string txt, vector <int>& lps){
            int len = 0;
            int i=1;
            lps[0]=0;
            
            while(i < pat.length()){
                if(pat[i] == pat[len]){
                    
                    lps[i] = len+1;
                    len++;
                    i++;
                }
                else{
                    if(len != 0)
                        len = lps[len-1];
                    else{
                        lps[i]=0;
                        i++;
                    }
                    
                }
            }
        }
        
        //main function
        vector <int> search(string pat, string txt)
        {
            int n = txt.length(), m=pat.length();
            vector <int> lps(m);    //of pattern size
            vector <int> ans;
            computeLongestPrefixSuffix(pat,txt, lps);
            // for(auto num: lps)
            //     cout<<num<<" ";
            int i=0,j=0;
            
            while(i<n){
                if(pat[j] == txt[i]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0)
                        j = lps[j-1];    //go to same previous occurence letter
                    else
                        i++;
                }
                
                if(j==m){
                    ans.push_back(i+1-j);
                    j = lps[j-1];   //go to same previous occurence letter for finding next search
                }
            }
            return ans;
            //code hee.
        }
