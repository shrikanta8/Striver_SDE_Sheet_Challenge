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
    vector<vector<int> > levelOrder(TreeNode* A) {
       vector<vector<int> > v;
        if(!A)
            return v;
        queue<TreeNode*> q;
        q.push(A);
        
        while(q.size()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* f = q.front();
                level.push_back(f->val);
                q.pop();
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            v.push_back(level);
        }
        return v; 
    }

};
