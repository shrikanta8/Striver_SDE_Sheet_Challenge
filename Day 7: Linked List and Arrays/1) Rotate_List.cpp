//you can traverse first k nodes then again a pointer from start. whhen the first node is reaching NUll, from there you have to chnage the nodes

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        int chk=1;
        ListNode* temp=head;
        
        //finding length of ll
        while(temp->next && ++chk)
            temp=temp->next;
        
        //assigning next of last node to first
        temp->next=head;
        k%=chk;
        k=chk-k;   
        
        //going to chk-k th node
        while(k--)
            temp=temp->next;
        
        head=temp->next;
        temp->next=NULL;
        return head;
    }
    
};
