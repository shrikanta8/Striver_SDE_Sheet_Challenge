class Solution {
public:
    bool isAnagram(string s, string t) {
        int c[27]={0},n=s.length(),n2=t.length();
        
        if(n!=n2) return false;
        
        for(int i=0;i<n;i++){
            c[s[i]-'a']++;
        }
        
        for(int i=0;i<n;i++){
            if(c[t[i]-'a'] < 1)
                return 0;
            c[t[i]-'a']--;
        }
        return 1;
    }
};
