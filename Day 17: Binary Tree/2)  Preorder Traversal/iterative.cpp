//solution 1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
       vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode* > st;
        st.push(root);
        
        while(st.size()){
            auto topNode = st.top();
            st.pop();
            ans.push_back(topNode->val);
            
            //first we will push right bcose the thing that we add first will be removed afterwards
            if(topNode->right !=NULL)
                st.push(topNode->right);
            if(topNode->left !=NULL)
                st.push(topNode->left);
        }
        return ans;
    }
};



//solution 2

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
    vector<int> nodes;
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while(node || s.size()){

            while(node!=NULL){  //going till left most
                v.push_back(node->val);
                s.push(node);
                node=node->left;
            }

            node=s.top();
            s.pop();
            
            node=node->right;
        }
        return v;
    }
};






