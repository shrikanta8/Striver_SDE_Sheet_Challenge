/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* makeTree(const vector<int> &A, int st,int en){
    
    if(st>en) return NULL;
    
    int mid = st + (en-st)/2;
    
    TreeNode* root =new TreeNode(A[mid]);
    
    root->left = makeTree(A,st,mid-1);
    root->right = makeTree(A,mid+1,en);
    
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return makeTree(A,0,A.size()-1);
}
