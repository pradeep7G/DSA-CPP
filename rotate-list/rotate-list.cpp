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
        if(!head || !head->next)
            return head;
        ListNode *newHead=NULL,*end=NULL;
        int len=0;
        ListNode *cur=head;
        while(cur){
            cur=cur->next;
            len++;
        }
        if(k%len==0)
            return head;
        if(len<k)
        {
            k=(k%len);
        }
        int diff=len-k;
        cur=head;
        int id=0;
        ListNode *prev=NULL;
        while(cur){
            if(cur->next==NULL){
                end=cur;
            }
            if(id<diff){
                prev=cur;
                newHead=cur->next;
                id++;
            }
            cur=cur->next;
        }
        end->next=head;
        prev->next=NULL;
        return newHead;
    }
};