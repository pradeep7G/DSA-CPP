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
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL,*cur=head;
        while(cur){
            ListNode *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        //reverse second half and traverse both lists and find maximum and return;
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *l2=reverse(slow->next);
        slow->next=NULL;
        ListNode *l1=head;
        int ans=INT_MIN;
        while(l1 && l2){
            ans=max(ans,l1->val + l2->val);
            l1=l1->next;
            l2=l2->next;
        }
        return ans;
    }
};