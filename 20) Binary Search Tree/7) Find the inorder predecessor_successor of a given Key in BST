/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

void findPreSuc(Node* root, Node*& pre, Node*& suc, int k)
{
    Node *root1= root;
    pre=NULL,suc =NULL;
    
    //finding successor
    while(root1!=NULL){
        
        if(k <= root1->key){
            root1=root1->left;
        }
        else{
            pre = root1 ;   //it can be our answer
            root1 = root1 -> right;
        }
    }
    
    //finding predecessor
    while(root!=NULL){
        
        if(k >= root->key){
            root=root->right;
        }
        else{
            suc = root;  //it can be our answer
            root=root->left;
        }
    }
    

// Your code goes here

}
