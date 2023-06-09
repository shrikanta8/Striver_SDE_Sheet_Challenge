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
    ListNode* rev(ListNode* node){
        if(node->next ==NULL){
            return node;
        }
        ListNode* h = rev(node->next);
        node->next->next = node;
        node->next = NULL;
        return h;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        ListNode* s=head, *f = head, *st = head;
        
        while(f->next && f->next->next){    
            s=s->next;
            f = f->next->next;
        }
        //now slow will point to mid value
        
        s->next=rev(s->next);
        s = s->next;
        while(s ){
            if(s->val!=st->val)
                return false;
            s=s->next;
            st=st->next;
        }
        return true;
        
    }
};
