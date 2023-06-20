/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    //NOT ALL VALUES IN VERTICAL LEVEL SHOULD BE SORTED
    //BUT ROW WISE IT SHOUL BE SORTED       //SEE THIS [3,1,4,0,2,2]
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return  vector<vector<int>>();
        map<int, map<int, multiset<int> > > mp;
        //vertical distance,horizontal distance and then multiset
        
        //using multiset because there may be duplicate values in tree here vertical and horizontal distance is same
        
        queue<pair<TreeNode*,pair<int,int> > > q;
        //keeping {Node,{vertical distance,horizontal distance}}
        
        q.push({root,{0,0}});
         vector<vector<int>> ans;
        
        while(q.size()){
            auto f = q.front();
            int v = f.second.first,h =  f.second.second;
            TreeNode* node = f.first;
            q.pop();
            mp[v][h].insert(node->val);
            
            if(node->left){
                q.push({node->left,{v-1,h+1}});
                //vert dist will get -1 and horiz dist will get +1
            }
            if(node->right){
                q.push({node->right,{v+1,h+1}});
            }
        }
        
       
        for(auto in:mp){    //all vertical values
             vector<int> dd;
            for(auto val:in.second){    //all horizontal values
                
                dd.insert(dd.end(),val.second.begin(),val.second.end());
                //inserting at end- one by one all the values which are there in multiset
            }
            //one vertical column is completed
            ans.push_back(dd);
        }
        return ans;
    }
};
