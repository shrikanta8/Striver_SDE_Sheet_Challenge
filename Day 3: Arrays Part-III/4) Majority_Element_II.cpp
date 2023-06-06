class Solution {
public:
    
    vector<int> majorityElement(vector<int>& A) {
        
        int n1=-1;  //first element
        int n2=-1;  //second element
        int c1=0,c2=0;
        
        for(auto num:A){
            if(num==n1) 
                c1++;
            else if(num==n2) 
                c2++;
            else if(c1==0){
                n1=num; 
                c1=1;
            }
            else if(c2==0){
                n2=num;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }

        int count1=0,count2= 0;
        vector<int> ans;
        
        //finding the count of elements
        
        for(auto num:A){
            if(num==n1) 
                count1++;
            else if(num==n2) 
                count2++;
        }
        
        int k =floor(A.size()/3);
        if( count1 > k ) 
            ans.push_back(n1);
        if( count2 > k ) 
            ans.push_back(n2);
        return ans;
        
    }

};
