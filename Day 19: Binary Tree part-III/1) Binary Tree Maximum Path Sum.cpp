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
    int maxi = INT_MIN;
    
    int maxPathSumHelper(TreeNode* root){
        if(root==NULL)
            return 0;
        
        //if leftVal or rightVal got -ve then it will return 0;
        int leftVal = max(0,maxPathSumHelper(root->left));
        int rightVal = max(0,maxPathSumHelper(root->right));
        
        maxi = max(maxi, leftVal+rightVal+root->val);
        //case when all values are -ve in tree: maxi will take the max negative value
        return max(leftVal, rightVal) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        maxPathSumHelper(root);
        return maxi;
    }
};
