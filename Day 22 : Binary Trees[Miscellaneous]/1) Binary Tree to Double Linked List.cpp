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
    //reverse pre order//Node RIGhT LEFT
    TreeNode* pre =NULL;
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        flatten(root->right);
        flatten(root->left);
        root->right=pre;    
        root->left =NULL;   //Left should be NULL always
        pre=root;   //pre will be having the  next value(connect to right)
        
    }
};
