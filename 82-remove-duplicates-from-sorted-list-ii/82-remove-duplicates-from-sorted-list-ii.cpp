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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next==NULL)
            return head;
       ListNode *dummy=new ListNode();
       ListNode *cur=head,*newHead=dummy;
       while(cur){
           if(cur->next && cur->val!=cur->next->val){
               if(dummy->next==NULL)
               {  
                   dummy->next=cur;
                   newHead=cur;
               }
               else{
                   newHead->next=cur;
                   newHead=cur;
               }
               cur=cur->next;
           }
           else{
               if(cur->next)
               {
                ListNode *prev=cur;
                cur=cur->next;
                while(cur && prev->val==cur->val)
                    cur=cur->next;
               }
               else{
                   newHead->next=cur;
                   newHead=cur;
                   cur=cur->next;
               }
           }
       }
        if(newHead)
        newHead->next=NULL;
        return dummy->next;
    }
};