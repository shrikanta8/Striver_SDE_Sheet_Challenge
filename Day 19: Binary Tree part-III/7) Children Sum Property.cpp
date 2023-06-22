/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    
    if( root==NULL)
            return;
    
     int total =0;
    
    if(root->left)
        total += root->left->data;  
    
    if(root->right)
         total += root->right->data;  
    
    if(total >= root->data){    
          root->data = total;
    }
    else{    //if sum of it's child nodes is less than root node data that means if we won't update it's child node's value then we have to decrease the root's value that is not possible
        if(root->left)
              root->left->data = root->data;
        if(root->right)
             root->right->data = root->data; 
    }
    
    changeTree(root->left);
    changeTree(root->right);
        
    int retSum = 0;
        
    //updating back values of root node
    
    if(root->left)
            retSum +=  root->left->data;
     if(root->right)
             retSum +=  root->right->data;    
    if(root->left || root->right){
         root->data = retSum;
    }

}  
