/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *s=head,*f=head,*pre=head;
        
        while(f && f->next && f->next->next){
            s=s->next;
            f=f->next->next;
            if(s==f) {
                 s=head;
                while(s!=f){
                    s=s->next;
                    f=f->next;
                }
                return f;
            }
        }
        return NULL;
       
    }
};
