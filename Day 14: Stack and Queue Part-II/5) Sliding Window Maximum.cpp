class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int B) {
        int n = A.size();
        deque<int> q;
        vector<int> v;
        if(n==1 || B==1){
            return A;
        }
            
        if(B>n)
            B=n;
        
        for(int i=0;i<n; i++){
            
            if(q.size() && q.front() <= i-B)    //ermoving from front the elements which is not in our range
                q.pop_front();
                
            while(q.size() && (A[i] > A[q.back()]) )    //elements in decreasing order
                q.pop_back();
                
            q.push_back(i);     
            
            if(i>=B-1)
                v.push_back(A[q.front()]);  //answer
        }
        return v;
    }
};
