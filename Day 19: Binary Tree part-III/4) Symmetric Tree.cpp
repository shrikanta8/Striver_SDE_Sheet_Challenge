class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetricHelper(root->left,root->right);
    }
    bool isSymmetricHelper(TreeNode* a, TreeNode* b){
        if(!a && !b)
            return true;
        
        if(a && b){
            return (a->val == b->val && isSymmetricHelper(a->left,b->right) && isSymmetricHelper(a->right,b->left));
        }
        return false;   //one is null only
    }
};
