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
        // int len=0;
        // ListNode* cur=head;
        // while(cur){
        //     cur=cur->next;
        //     len++;
        // }
        // int diff=len-n-1;
        // cur=head;
        // while(cur && diff>0){
        //     cur=cur->next;
        //     diff--;
        // }
        // if(diff<0){
        //     head=head->next;
        // }
        // else
        // cur->next=cur->next->next;
        // return head;
        ListNode *ptr=head,*cur=head;
        for(int i=0;i<n;i++){
            cur=cur->next;
        }
        ListNode *pre=NULL;
        while(cur){
            pre=ptr;
            ptr=ptr->next;
            cur=cur->next;
        }
        if(!pre){
            return ptr->next;
        }
        pre->next=ptr->next;
        return head;
    }
};