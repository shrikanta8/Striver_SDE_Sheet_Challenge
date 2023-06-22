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
    TreeNode* pre=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = pre;  //pointing to pre 
        root->left = NULL;  //should be upated to NULL
        
        pre=root;   //keeping track of previous node
    }
};
