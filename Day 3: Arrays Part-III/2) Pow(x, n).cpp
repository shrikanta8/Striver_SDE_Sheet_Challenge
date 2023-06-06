class Solution {
public:
    double myPow(double x, int n) {
        
        long nn=n;
        double ans=1;
        if(n<0)
            nn=nn*-1;

        while(nn){
            if(nn%2==1){
                nn-=1;
                ans = ans * x;
            }
            else{
                nn = nn/2;
                x=x*x;
            }
        }
        if(n<0)
            return (double)1/ans;
        return ans;
    }
};
