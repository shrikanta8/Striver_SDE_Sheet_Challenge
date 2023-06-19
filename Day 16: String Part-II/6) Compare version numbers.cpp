class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(),len2 = version2.length();
        
        int i=0,j=0,num1=0,num2=0;
        
        while(i<len1 || j<len2){
            
            // || is used it means it will run till both string gets completed
            
            while(i < len1 && version1[i]!= '.'){
                num1 = (num1*10) + (version1[i++]-'0'); //0 will be automatically ignored
            }
            
            while(j < len2 && version2[j]!= '.'){
                num2 = (num2*10) + (version2[j++]-'0');
            }
            
            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;
            
            num1=0,num2=0;  //if any of the string is completed then it will have num1 as 0 in it
            
            i++;    //since now both i and j indices have '.' in it
            j++;
            
        }
        return 0;
    }
};
