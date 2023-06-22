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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd, int inStart, int inEnd, unordered_map<int ,int>& mp){
        
        if( preStart > preEnd )// or  inStart > inEnd
             return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inorderLoc = mp[root->val];
        int numsLeft = inorderLoc-inStart;  //these same numbers will be there in preorder's left 
            
        root->left = buildTreeHelper(preorder, inorder, preStart+1, preStart+numsLeft ,inStart, inorderLoc-1, mp);
        root-> right = buildTreeHelper(preorder, inorder, preStart+numsLeft+1, preEnd, inorderLoc+1, inEnd ,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int ,int> mp; //it will keep location of numbers in inorder array
        int n =preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        
        
        return buildTreeHelper(preorder,inorder,0,n-1,0,n-1, mp);
    }
};
