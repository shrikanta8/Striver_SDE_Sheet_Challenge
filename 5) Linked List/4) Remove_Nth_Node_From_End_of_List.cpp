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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();//dummy node pointing to head
        
        start -> next =head;
        
        ListNode *slow=start;
        ListNode *fast=start;
        for(int i=1;i<=n ;i++)
            fast = fast->next;  //traversing n steps
        
        while(fast->next !=NULL){
            fast = fast->next;
            slow = slow-> next;
        }
        // slow's next will be the element to delete
        
        ListNode *temp = slow-> next;
        slow-> next= slow-> next ->next;
        delete temp;
        return start->next;
    }
};
