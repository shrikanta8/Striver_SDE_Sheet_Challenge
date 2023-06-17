//brute force=>
  traversing on left and right of every index and finding min on both sides
  O(n^2) tc
 
 
//using 2 stack 
  one for min element from left and other for min elemnt on right
  
  
//using one stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size(),width;
        stack<int> st;
        int ans=INT_MIN;
        
        for(int i=0;i<=n;i++){  
            //when all elements are in ascending order in stack then n is considered as smaller element on right
            
            while(st.size() && (i==n || heights[st.top()] > heights[i] )){
                
                int height=heights[st.top()];   
                st.pop();
                if(st.empty()){
                    width = i;      //0 th index is considered as left's min
                }
                else{
                    width = i-st.top()-1;   //st.top is considered as left's min
                }
                ans = max(ans, width * height);
                
            }
            st.push(i);
        }
        return ans;
        
    }
};
