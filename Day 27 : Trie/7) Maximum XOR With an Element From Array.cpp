//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

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
    void buildTree(int ele){
        Node* temp = root;
        for(int i=31;i>=0;i--){
            int currVal = (ele>>i) & 1;
            if(temp->isPresent(currVal)==false){
                temp->addValue(currVal);
            }
            temp= temp->nei[currVal];
        }
    }
    int findMax(int num){
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int, pair<int,int> > > arr; 
        int q=queries.size(),ind=0,n=nums.size();
        for(int i=0;i<q;i++){
            arr.push_back({queries[i][1],{queries[i][0],i}});
        }
        root = new Node();
        vector<int> ans(q);
        sort(arr.begin(),arr.end());        //sorting according to m value;

        for(int i=0;i<q;i++){
            //only adding values in tree which are less then m
            while(ind<n && arr[i].first>=nums[ind]){
                buildTree(nums[ind++]);
            }

            if(ind == 0){   //noting is there in tree
                ans[arr[i].second.second] = -1;
            }
            else{
                ans[arr[i].second.second] = findMax(arr[i].second.first)^(arr[i].second.first);
            }
        }
        return ans;
    }
};
