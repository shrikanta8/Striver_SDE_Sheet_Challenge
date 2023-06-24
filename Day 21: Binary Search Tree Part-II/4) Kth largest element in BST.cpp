class Solution
{
    public:
    Node* traversal(Node *root, int &k){
        
        if(!root) return NULL;
        
        Node* r = traversal(root->right,K);
        if(r)
            return r;
        K--;
        if(K==0)
            return root;
        
        return traversal(root->left,K);
        
        //no need to write this bottom lines as, at the end it will be returning the value
        // if(l)
        //     return l;

    }
    int kthLargest(Node *root, int K)
    {
        return traversal(root,K)->data;
        //Your code here
    }
    
};
