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
    void findAns(TreeNode* root, vector<vector<int>>& ans){
        queue<TreeNode*> s;
        s.push(root);
        int len = 1;bool flag=1;
        while(s.size()){
            len = s.size();
                int i=0;
            vector<int> v(len);
            while(len--){
                TreeNode* temp = s.front();
                s.pop();
                if(temp->left) s.push(temp->left);
                if(temp->right) s.push(temp->right);
                
                if(flag){
                    v[i++] = temp->val;
                }
                else{
                    v[len] = temp->val;
                }
            }
            flag = !flag;
            ans.push_back(v);
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        findAns(root,ans);
        return ans;
    }
};
