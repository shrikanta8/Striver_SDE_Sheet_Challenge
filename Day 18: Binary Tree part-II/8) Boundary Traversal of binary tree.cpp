/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

    // Write your code here.

    void leftSide(TreeNode<int>* root, vector<int>& ans){
        
        if(root==NULL)
            return;
        
        if(root->left){ //we are not considering extreme left node here
        
            ans.push_back(root->data);  // push values from top to bottom!
            leftSide(root->left, ans);   
            //go to extreme left 
            
        }
        else if(root->right){
            ans.push_back(root->data);
            leftSide(root->right, ans);
        }
            
        
    }
    void leavesInorder(TreeNode<int>* root, vector<int>& ans){
        
        if(root==NULL)
            return;
            
        leavesInorder(root->left, ans);
        
        //extreme left and extreme right node are being taken here
        if(root->left==NULL && root->right==NULL)   
            ans.push_back(root->data);
        
        leavesInorder(root->right, ans);
        
    }
    
    void rightSide(TreeNode<int>* root, vector<int>& ans){
        if(root==NULL)
            return;
        
        if(root->right){
            //we are not considering extreme right node here
             rightSide(root->right, ans);    //go to extreme right and then push values from bottom to top!
             ans.push_back(root->data);
        }
        else if(root->left){
            rightSide(root->left, ans);
            ans.push_back(root->data);
        }
    }
    vector <int> traverseBoundary(TreeNode<int>* root)
    {
        vector<int> ans;

        if(root==NULL)
            return ans;
        
        ans.push_back(root->data);
        
        leftSide(root->left,ans);   //left side 
        
        if(root->left || root->right)   //check that if root children's are there or not  
            leavesInorder(root,ans);
        
        rightSide(root->right,ans); //right side
        
        return ans;
        //Your code here
    }
