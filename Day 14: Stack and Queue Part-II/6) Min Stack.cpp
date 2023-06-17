//https://www.interviewbit.com/problems/min-stack/

stack<pair<int,int>> st;        //<element, min element till now>

MinStack::MinStack() {
    stack<pair<int, int> > p; 
    st = p; 
}

void MinStack::push(int x) {
    int minEle=x;
    
    if(!st.empty())
        minEle= min(st.top().second,x);
    st.push({x,minEle});
}

void MinStack::pop() {
    if(!st.empty())
        st.pop();
}

int MinStack::top() {
    return (st.empty())?(-1):(st.top().first);
}

int MinStack::getMin() {
    return (st.empty())?(-1):(st.top().second);
}
