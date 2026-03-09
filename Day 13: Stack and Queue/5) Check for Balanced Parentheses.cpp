class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(st.size() && st.top() =='{' && ch =='}' || st.top() =='(' && ch ==')'  || st.top() =='[' && ch ==']' )
                    st.pop();
                    
                else if(ch =='{' || ch =='(' || ch =='[')
                    st.push(ch);
                else{
                    return false;   
                }
            }
        }
        if(st.size()) 
            return false;
        return true;
    }
};



Stack<Character> stack = new Stack<Character>();
    for (char c : s.toCharArray()) {
        if (c == '(')
            stack.push(')');
        else if (c == '{')
            stack.push('}');
        else if (c == '[')
            stack.push(']');
        else if (stack.isEmpty() || stack.pop() != c)
            return false;
    }
    return stack.isEmpty();
