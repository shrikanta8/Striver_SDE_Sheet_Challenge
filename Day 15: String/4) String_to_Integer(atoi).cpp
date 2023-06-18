class Solution {
public:
    int myAtoi(string s) {
        int num=0,i=0,n=s.length(),sign=1;
        
        while(s[i]==' ') i++;
        
        if(s[i] =='-' || s[i] =='+'){
            if(s[i] =='-')
                sign*=-1;
            i++;
        }
        
        while(s[i] >='0' && s[i] <='9'){
        
            //s[i]>'7' because if s[i] > 7 so it will be out of INT_MAX range
            //if it will be >7 then INT_MIN will get counted
            
            //num > INT_MAX/10 ...where num's end value is 65 so it will always be greater than INT_MAX range when a new digit is being appended
            
            if(num > INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7') ){
                if(sign==1)
                    return INT_MAX;
                return INT_MIN;
            }
            num = num*10 + (s[i]-'0');
            i++;
        }
    
     return num*sign;   
    }
};
