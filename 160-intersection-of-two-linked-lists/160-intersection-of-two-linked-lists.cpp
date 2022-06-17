/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *cur1=headA,*cur2=headB;
        while(cur1)
        {
            len1++;
            cur1=cur1->next;
        }
        while(cur2){
            len2++;
            cur2=cur2->next;
        }
        cur1=len1>len2?headA:headB;
        cur2=len1>len2?headB:headA;
        int diff=abs(len1-len2);
        while(diff--){
            cur1=cur1->next;
        }
        while(cur1 && cur2){
            if(cur1==cur2){
                return cur1;
            }
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return NULL;
    }
};