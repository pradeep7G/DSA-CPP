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
    ListNode* partition(ListNode* head, int x) {
       ListNode node1(-1),node2(-1);
       ListNode *l1=&node1,*l2=&node2;
       ListNode *cur=head;
       while(cur){
           if(cur->val < x){
               l1->next=cur;
               l1=l1->next;
           }
           else{
               l2->next=cur;
               l2=l2->next;
           }
           cur=cur->next;
       }
       l2->next=NULL;
       l1->next=(&node2)->next;
       return (&node1)->next;
    }
};