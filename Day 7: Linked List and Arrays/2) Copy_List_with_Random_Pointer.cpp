/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* start=head;
        Node* last;
        
        //making copy of each node 
        while(start!=NULL){
            last=start->next;
            Node* copy = new Node(start-> val);
            start->next=copy;
            copy->next= last;
            start = last;
        }
        
        //assigning random pointers in new nodes 
        start=head;
         while(start!=NULL){
            if(start->random)
                start->next->random= start->random->next;
            start=start->next->next;
        }
        
        //get the original list
        //get the new list
        start=head;
        Node *dup=head->next,*ret=head->next;
        
        while(start!=NULL){
            last=start->next->next;
            start->next = last;
            if(dup->next)
                dup->next=dup->next->next;
            dup= dup->next;
            start = last; 
        }
        return ret;
    }
};
