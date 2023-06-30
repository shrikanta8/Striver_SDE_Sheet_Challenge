class Solution {
public:
    class Node{
        public:
        vector<Node*> nei;
        Node(){
            nei.resize(2);
        }
        bool isPresent(int currVal){
            return nei[currVal] != NULL;
        }
        void addValue(int currVal){
            nei[currVal] = new Node();
        }
    };
    Node* root;
    void buildTree(vector<int>& nums){
        
        for(auto ele: nums){
            Node* temp = root;
            for(int i=31;i>=0;i--){
                int currVal = (ele>>i) & 1;
                if(temp->isPresent(currVal)==false){
                    temp->addValue(currVal);
                }
                temp= temp->nei[currVal];
            }
        }
    }
    int findAns(int num){
        Node* temp = root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int curr = (num>>i) & 1;
            int tar = !curr;
            if(temp -> nei[tar] != NULL){
                ans =ans*2+tar;
                temp = temp->nei[tar];
            }
            else{
                ans = ans*2 + curr;
                temp = temp->nei[curr];
            }
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        buildTree(nums);
        int ans=0;
        for(auto num:nums){
            ans = max(ans,num^findAns(num));
        }
        return ans;
    }
};
