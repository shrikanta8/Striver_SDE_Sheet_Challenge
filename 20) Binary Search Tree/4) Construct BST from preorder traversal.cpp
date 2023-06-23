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
    //root's value is used as left bound and right bound is infinity
    int i=0;
    
    TreeNode* bst(vector<int>& preorder, int maxVal, int &i){
        
        if(i==preorder.size() || preorder[i] > maxVal)     
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = bst(preorder, root->val, i);   //on left side the value should be less than current root value
        root->right = bst(preorder, maxVal, i);     //on right side the value should be greater than the maxVal
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, INT_MAX,i);
    }
};
