class Solution {
public:
    string countAndSay(int n) {
        string pre="1",cur;
        if(n==1)
            return pre;
        n--;
        
        while(n--){
            int len = pre.length(),count=1;
            cur="";
            
            for(int i=1;i<=len;i++){
                
                if(i!= len && pre[i] == pre[i-1]){
                    count++;
                }
                else{
                    cur += (count+'0');
                    cur += pre[i-1];
                    count = 1;
                }
            }
            
            pre=cur;  //back assigning pre as cur string for next manipulation
        }
        return pre;
    }
};
