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
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse;   
    public:
    
    BSTIterator(TreeNode* root, bool value){
       reverse=value;
        traverse(root);
    }
    
    void traverse(TreeNode* root){
        
        while(root){
            st.push(root);
            if(reverse){ 
                 root=root->left;   //for next value(LNR)
            }
            else{
                root=root->right;    //for before value(RNL)
            }
        }
    }
    
    int next(){
        TreeNode* node = st.top();
        st.pop();
        
        if(reverse)
            traverse(node->right);  //for next value(LNR)
        else
            traverse(node->left);    //for before value(RNL)
        
        return node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        BSTIterator l(root,true), r(root,false);
        //two objects-  l for next value(LNR)
        //r for before value(RNL);
        
        int first = l.next();
        int last = r.next();
        
        while(first < last){    //2 pointer logic
            if(first+last==k)
                return true;
            else if(first+last < k)
                first = l.next();   //next greater value
            else
                last = r.next();    //next smaller value
        }
        
        return false;   //no answer
        
    }
};
