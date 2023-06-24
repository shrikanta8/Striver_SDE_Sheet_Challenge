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
class BSTIterator {
    stack<TreeNode*> st;
public:
    
    void pushValues(TreeNode* root){
        //all values in left side are being added
        while(root){    
            st.push(root);
            root=root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        pushValues(root);
            
    }
    
    int next() {
        //taking next value
        TreeNode* node = st.top();
        st.pop();
        pushValues(node->right);    //left node is over now next is right in inorder
        return node->val;
    }
    
    bool hasNext() {
        //if stack has some size it means there is some next value
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
