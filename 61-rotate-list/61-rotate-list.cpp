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
    ListNode* rotateRight(ListNode* head, int k) {
        //k%len
       int len=0;
       ListNode* cur=head;
       while(cur){
           len++;
           cur=cur->next;
       }
       if(len==0 || k==0)
           return head;
       int shift=k%len;
       if(shift==0 || !head || !head->next)
           return head;
       cur=head;
       ListNode *end=NULL,*prev=NULL,*newHead=NULL;
       int head_node=0;
       while(cur){
           if(cur->next==NULL)
               end=cur;
           if(head_node+1==len-shift){
               prev=cur;
               newHead=cur->next;
           }
           cur=cur->next;
           head_node++;
       }
       end->next=head;
       prev->next=NULL;
       return newHead;
    }
};