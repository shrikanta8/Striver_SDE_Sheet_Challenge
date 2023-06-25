class Solution {
public:
    int findKthLargest(vector<int>& A, int B) {
         int n=A.size();
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<B;i++){
            pq.push(A[i]);
        }
        for(int i=B;i<n;i++){
            if(A[i] > pq.top()){
                pq.pop();
                pq.push(A[i]);
            }
        }
        
        return pq.top();   
    }
};

//stl
class Solution {
public:
    int findKthLargest(vector<int>& A, int B) {
         // nth_element(A.begin(), A.begin()+B-1,A.end(), greater<int>());
        partial_sort(A.begin(), A.begin()+B,A.end(), greater<int>());
        // for(auto n:A)
        //     cout<<n<<" ";
        return A[B-1];   
    }
};
