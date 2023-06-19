class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1=haystack.length(),l2=needle.length();
        for(int i=0;;i++){
            for(int j=0;;j++){
                if(j==l2)
                    return i;
                if(i+j==l1)
                    return -1;
                if(haystack[i+j] != needle[j])
                    break;
            }

        }
    }
};
