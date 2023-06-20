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
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int> > q;
        
        q.push({root,0});
        
        int ans=0,first,last;
        
        while(q.size()){
            int n=q.size();
            int minn = q.front().second;    //1st node in that row
            
            for(int i=0;i<n;i++){
                
                int val = q.front().second-minn;    //making them in 1 based range
                
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i==0)    // first node in that row
                    first = val;
                
                if(i==n-1)  // last node in that row
                    last = val;
                
                if(node->left){
                    q.push({node->left,val*1LL*2+1});
                }
                if(node->right){
                    q.push({node->right,val*2+2});
                }
            }
            ans = max(ans,last-first+1);    //will be our width
        }
        return ans;
    }
};
