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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        //checking whether size is less than k 
        int j=0;
        while(j<k && cur){
            cur=cur->next;
            j++;
        }
        if(j!=k) return head;   //less than k
        
        ListNode *prev=head, *var1=head,*var2=NULL;
        int i=0;
        
        while(i<k ){     //reverse function
            var1= prev->next;
            prev->next = var2;
            var2 = prev;
            prev = var1;
            i++;
        }
        
        //current head will point to the pointer it returns
        //var1 will be the starting of next partition
        head->next =  reverseKGroup(var1,k);
        return var2;
    }
};
