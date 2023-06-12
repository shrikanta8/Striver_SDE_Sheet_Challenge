class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        string str="";
        int fact=1;
        for(int i=1;i<n;i++){
            fact *= i;
            num.push_back(i);
        }
        k--;
        num.push_back(n);
        while(1){
            str += to_string(num[k/fact]);
            num.erase(num.begin() + (k/fact) );
            
            k = k%fact;
            if(num.size()==0) 
                break;
            fact /= num.size(); 
        }
        return str;
    }
};
