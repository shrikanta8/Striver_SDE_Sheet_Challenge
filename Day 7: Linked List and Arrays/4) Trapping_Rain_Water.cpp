class Solution {
public:
    int trap(vector<int>& A) {
        int n=A.size();
        int r = n-1,l=0,maxLeft=0,maxRight=0,ans=0;

        while(l<r){
            
            if(A[l] <= A[r]){

                if(maxLeft <= A[l] ) //since A[l] is greater => there is no greater value on lhs than A[l] =>can't store water
                    maxLeft = A[l];
                else 
                    ans += (maxLeft-A[l]);      //since current A[l] is less than maxLeft && A[l] is also less than A[r] => water can be stored here

                l++;
            }
            else{

                if(maxRight<= A[r] ) 
                    maxRight = A[r];
                else
                    ans += (maxRight - A[r]);

                r--;

            }
        }
        return ans;
    }
};
