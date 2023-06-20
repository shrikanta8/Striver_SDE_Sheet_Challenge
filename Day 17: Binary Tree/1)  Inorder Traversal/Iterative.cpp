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
#include<stack>
#include<vector>
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root==NULL)
            return v;
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while(node || s.size()){

            while(node!=NULL){  //going till left most
                s.push(node);
                node=node->left;
            }

            node=s.top();
            s.pop();
            v.push_back(node->val);
            node=node->right;
        }
        return v;
    }
};
