class Solution {
public:
    vector<int> preorderTraversal(TreeNode* node) {
        vector<int> preorder;
        
        if(node==NULL)
            return preorder;
        
        TreeNode* root = node;
        
        while(root !=NULL){
            
            if(root->left == NULL){
                //left most node
                preorder.push_back(root->val);
                root=root->right;   //it will go back to parent Node by LINKED line
            }
            else{
                TreeNode* pre = root->left;
                //going to rightmost node
                while(pre->right && pre->right!= root){
                    pre = pre->right;
                }
                
                //linking the rightmost node to root node
                if(pre->right ==NULL){
                    pre->right = root;
                    preorder.push_back(root->val);  //node is our answer, then we are moving to left
                    root=root->left;
                }
                // unlinking back the rightmost node to root node
                else{
                    pre->right =NULL;
                    root=root->right;  //root left is over of (Node Left  Right ), now going to right side
                }
                    
            }
        }
        return preorder;
    }
};
