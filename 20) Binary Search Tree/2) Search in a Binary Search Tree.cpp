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
    TreeNode* searchBST(TreeNode* A, int v) {
        
        if(!A) return NULL;
        
        if(A->val == v) return A;
        
        if(A->val > v) 
            return searchBST(A->left,v);
        else
            return searchBST(A->right, v);
        return NULL;
    }
};
