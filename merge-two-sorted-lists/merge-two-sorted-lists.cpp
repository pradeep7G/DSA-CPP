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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy=new ListNode(-1);
        ListNode *trav=dummy;
        while(list1 && list2){
            if(list1->val <= list2->val)
            {
                trav->next=list1;
                trav=trav->next;
                list1=list1->next;
            }
            else
            {
                trav->next=list2;
                trav=trav->next;
                list2=list2->next;
            }
        }
        if(!list1){
            trav->next=list2;
        }
        else if(!list2){
            trav->next=list1;
        }
        return dummy->next;
    }
};