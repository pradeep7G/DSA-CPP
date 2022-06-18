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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next){
            if(head && !head->next)
            {
                delete head;
                return NULL;
            }
            return head;
        }
        ListNode *slow=head,*fast=head;
        ListNode *prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev==NULL){
            return slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};