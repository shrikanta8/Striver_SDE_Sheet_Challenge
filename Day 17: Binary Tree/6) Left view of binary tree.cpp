/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
void traversal(Node *root,vector<int>& ans, int level){
    if(!root) return;
    
    //it will add only the values of node which are coming for the first  time
    if(ans.size()==level)
        ans.push_back(root->data);
        
     traversal(root->left,ans,level+1);
     traversal(root->right,ans,level+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    traversal(root,ans,0);
    return ans;
   // Your code here
}



