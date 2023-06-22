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
    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder,int postStart,int postEnd, int inStart, int inEnd, unordered_map<int ,int>& mp){
        
        if( postStart > postEnd )// or  inStart > inEnd
             return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inorderLoc = mp[root->val];
        int numsRight = inEnd-inorderLoc;  //these same numbers will be there in postorder's right 
            
        root->left = buildTreeHelper(postorder, inorder,postStart ,postEnd-numsRight-1 ,inStart , inorderLoc-1 , mp);
        root-> right = buildTreeHelper(postorder, inorder,postEnd-numsRight, postEnd-1 ,inorderLoc+1 , inEnd , mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int ,int> mp; //it will keep location of numbers in inorder array
        int n =postorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        
        
        return buildTreeHelper(postorder,inorder,0,n-1,0,n-1, mp);
    }
};
