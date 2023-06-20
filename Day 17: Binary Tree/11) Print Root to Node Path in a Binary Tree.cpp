//https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool inorder(TreeNode* A, int B,vector<int>& ans){
    if(!A)
        return 0;
        
    ans.push_back(A->val);
    
    if(A->val == B){
        return 1;
    }
    
    
    if (inorder(A->left,B,ans) || inorder(A->right,B,ans) ) //if true then return because we got the value
        return 1;
    
    ans.pop_back(); //it means it is not our path
    return 0;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    inorder(A,B,ans);
    return ans;
}
