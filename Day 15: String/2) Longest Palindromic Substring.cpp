class Solution {
public:
    int checklongestPalindrome(string s,int start,int end){
        if(start > end) return 0;
        int n= s.length();
        while(start>=0 && end<n && s[start]==s[end]){
            start--;
            end++;
        }
        return end-start-1; //length of palindrome
        
    }
    
    string longestPalindrome(string s) {
        
        int start=0,end=0,maxLen;
        
        for(int i=0;i<s.length();i++){
            
            int l1 = checklongestPalindrome(s,i,i); //odd length
            int l2 = checklongestPalindrome(s,i,i+1);   //even length
             maxLen = max(l1,l2);
            
             if(end-start < maxLen){
                start = i- ((maxLen-1)/2); //-1 because we are not considering 0 based length size 
                end = i +( maxLen/2);
            }
        }
        
        return s.substr(start,(end-start)+1);
    }
};


//n^2 tc
