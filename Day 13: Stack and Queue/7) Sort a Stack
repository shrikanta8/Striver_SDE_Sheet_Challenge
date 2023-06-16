#include <bits/stdc++.h> 
void insertAtCorrectPosition(int x, stack<int>& s){
    if(s.size() ==0 || s.top() < x)
        s.push(x);
    else{
        int ele = s.top();
        s.pop();
        insertAtCorrectPosition(x,s);   //we are keeping x at correct position by popping smaller elements from top 
        s.push(ele);    //piushing back the popped elements
    }
    
}
void reverse(stack<int>& s){
    if(s.size()){
        int x = s.top();
        s.pop();
        reverse(s);
        insertAtCorrectPosition(x,s);   //we are starting with element which is at the bottommost of the stack 
    }
}
void sortStack(stack<int> &s)
{
	reverse(s);
	// Write your code here
}
