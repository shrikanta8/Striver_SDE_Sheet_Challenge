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
    ListNode* reverseList(ListNode* head) {
        ListNode* var1,*var2=NULL;
        while(head!=NULL)
        {
            var1=head->next;
            head->next=var2;
            var2=head;
            head=var1;
        }
        return var2;
    }
};
