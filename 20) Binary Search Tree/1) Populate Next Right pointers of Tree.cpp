/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node *root) {
        if(!root)
            return NULL;
        
        Node *cur=root,*pre =NULL;
        
        while(cur->left){   //cur should not be at last level
            
            pre = cur;  //cur is pointing to the first node of each level
            
            while(pre){
                pre->left->next = pre->right;
                
                if(pre->next)
                    pre->right->next = pre->next->left;
                pre = pre->next;
            }
            
            cur = cur->left;
        }
        return root;
    }
};
