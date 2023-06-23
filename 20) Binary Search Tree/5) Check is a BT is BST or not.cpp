
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
    bool traversal(TreeNode* root,long low, long h){
        if(!root)
            return true;
        
        if(root->val<=low || root->val>=h) 
            return false;
        
        //for left high will become root->val
        return (traversal(root->left,low,root->val) && traversal(root->right,root->val,h) );
        
        //if any of them is false then return false
    }
    bool isValidBST(TreeNode* root) {
        if(!root )
            return true;
        return traversal(root, LONG_MIN,LONG_MAX);
    }
};
