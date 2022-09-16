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
    ListNode* solve(ListNode *head){
        ListNode *cur=head;
        ListNode *dummy=new ListNode(-1e5);
        for(;cur;){
            ListNode* trav=dummy;
            for(;trav->next and trav->next->val < cur->val;)
                trav=trav->next;
            ListNode *nxt=cur->next;
            cur->next=trav->next;
            trav->next=cur;
            cur=nxt;
        }
        return dummy->next;
    }
    ListNode* insertionSortList(ListNode* head) {
       return solve(head);
       ListNode *cur=head;
       ListNode *dummy=new ListNode(-10000);
       for(;cur;){
          ListNode* trav=dummy;
          for(;trav->next && trav->next->val < cur->val;){
              trav=trav->next;
          }
          ListNode* next=cur->next;
          cur->next=trav->next;
          trav->next=cur;
          cur=next;
       }
       return dummy->next;
    }
};