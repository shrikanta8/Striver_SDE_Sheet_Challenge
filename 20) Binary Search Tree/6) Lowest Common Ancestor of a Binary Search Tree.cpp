/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
    if(!root) 
        return NULL;
        
    if(root->val == a->val || root->val == b->val)
        return root;
        
    if(a->val<=root->val && b->val>=root->val || b->val<=root->val && a->val>=root->val)
        return root;
    else if(a->val<=root->val && b->val<=root->val)
        return lowestCommonAncestor(root->left,a,b);
    else
        return lowestCommonAncestor(root->right,a,b);
    }
};
