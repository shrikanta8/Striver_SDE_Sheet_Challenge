int countNum(vector<vector<int> > &A, int midVal,int r){
    
    int count=0;
    for(int i=0;i<r;i++){
        count += upper_bound( A[i].begin(),A[i].end(),midVal) - A[i].begin();
    }
    return count;
}

int Solution::findMedian(vector<vector<int> > &A) {
    
    int r=A.size(),c=A[0].size();
    int st = 1,end = 1e9;
    
    int midVal = (r*c)/2;   //half the numbers
    
    while(st<=end){
        
        int mid = (st+end) >> 1;
        
        if(countNum(A, mid, r) <= midVal ){
            st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return st;
}
