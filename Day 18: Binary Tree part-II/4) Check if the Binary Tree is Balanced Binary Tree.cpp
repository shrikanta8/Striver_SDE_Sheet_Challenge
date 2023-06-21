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
    bool isBalanced(TreeNode* A) {
        if(!A) 
            return true;
        return findAns(A) != -1;
    }
    int findAns(TreeNode* A){
        if(!A) return 0;

        int l = findAns(A->left);
        if(l==-1) return -1;

        int r = findAns(A->right);
        if(r==-1) return -1;

        if(abs( l-r ) > 1)  //not balanced
          return -1;

        return max( l,r )+1;
    }
};
