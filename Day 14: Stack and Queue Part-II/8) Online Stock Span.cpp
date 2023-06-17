class StockSpanner {
public:
    stack<pair<int,int> > st;       //<price, current index >
    int ind;
    StockSpanner() {
        ind=1;
    }
    
    //if i+1 th value is greater than i th value and if i th value if greater than 5 consecutive elemnts in front of it then i+1 is also greater tha that 5 lements and  ith value 
    int next(int price) {
        int ans;
        //keeping values in decreasing order
        while(st.size() && st.top().first <= price){
            st.pop();
        }
        
        if(st.size())
            ans=ind-st.top().second;
        else
            ans=ind;    //whole values are lesser than that ith value
        
        st.push({price,ind++});
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
