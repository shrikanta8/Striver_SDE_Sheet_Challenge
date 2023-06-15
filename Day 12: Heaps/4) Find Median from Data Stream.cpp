class MedianFinder {
public:
    priority_queue<int> q1;  //MaxHeap
    priority_queue<int,vector<int> ,greater<int> > q2; //minHeap
    
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        
        //at starting if q1 is empty add to q1
        
        if(q1.empty() || q1.top()>num){ 
            //if q1 top value is greater than num then only add to q1
            q1.push(num);
        }
        else{
            q2.push(num);
        }
        
        //both size should not be greater than 1
        if(q1.size() > q2.size() + 1){  
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size() > q1.size() + 1){
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        
        
        int f=q1.size() ;
        int s= q2.size();
        
        if(f==s)    //even numbers in both, so answer will be median of 2 middle no's
            return ((double)q1.top()+ q2.top())/2;
        else if(f>s)    //if q1 has greater then that is ans
            return q1.top();
        else
             return q2.top();
        
        
    }
};
