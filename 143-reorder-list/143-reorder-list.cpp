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
    ListNode* reverse(ListNode *head){
        ListNode *prev=NULL,*cur=head;
        while(cur){
            ListNode *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //find mid and reverse and do
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * l2=reverse(slow->next);
        slow->next=NULL;
        ListNode *l1=head;
        ListNode *trav=new ListNode(-1);
        ListNode *ans=trav;
        int i=1;
        while(l1 && l2){
            if(i%2==1){
                ans->next=l1;
                ans=ans->next;
                l1=l1->next;
            }
            else{
                ans->next=l2;
                ans=ans->next;
                l2=l2->next;
            }
            i++;
        }
        if(!l2){
            ans->next=l1;
            ans=ans->next;
        }
        else{
            ans->next=l2;
            ans=ans->next;
        }
        ans->next=NULL;
        head=ans->next;
    }
};