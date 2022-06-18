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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre=NULL,*cur=head;
        ListNode *dummy=new ListNode(-1);
        ListNode *track=dummy;
        while(cur){
            if(cur->val != val){
              track->next=cur;
              track=track->next;   
              cur=cur->next;   
            }
            else{
                while(cur && cur->val == val){
                    cur=cur->next;
                }
                if(cur==NULL)
                    track->next=NULL,track=track->next;
            }
        }
        return dummy->next;
    }
};