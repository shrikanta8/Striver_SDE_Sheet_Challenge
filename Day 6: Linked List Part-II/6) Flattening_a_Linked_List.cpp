    
Node* mergeList(Node *r1,Node *r2){
    Node *head= new Node(0);
    Node* temp=head;
    
    while(r1 && r2){
        if(r1->data <= r2->data){
            temp->bottom = r1;
            r1=r1->bottom;
            temp= temp->bottom;
        }
        else{
            temp->bottom = r2;
            r2=r2->bottom;
            temp= temp->bottom;
        }
    }
    if(r1){
        temp->bottom =r1;
    }
    if(r2){
        temp->bottom =r2;
    }
    return head->bottom;
}
Node *flatten(Node *root)
{
    if(!root || !root->next) return root;
    
    root->next = flatten(root->next);
    root = mergeList(root,root->next);
    return root;
   // Your code here
}
