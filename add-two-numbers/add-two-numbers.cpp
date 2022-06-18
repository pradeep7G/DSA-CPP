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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=0,len2=0;
        ListNode *cur1=l1,*cur2=l2;
        while(cur1){
            len1++;
            cur1=cur1->next;
        }
        while(cur2){
            len2++;
            cur2=cur2->next;
        }
        if(len1>len2)
            cur1=l1,cur2=l2;
        else
            cur1=l2,cur2=l1;
        int carry=0;
        while(cur1 && cur2){
            int digit=(cur1->val+cur2->val+carry);
            cur1->val=digit%10;
            carry=(digit)/10;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        while(cur1){
            int digit=(cur1->val+carry);
            cur1->val=digit%10;
            carry=digit/10;
            if(carry==0)
                break;
            if(cur1->next==NULL)
                break;
            cur1=cur1->next;
        }
        if(carry){
            if(cur1==NULL){
                cur1=(len1>len2)?l1:l2;
                while(cur1->next){
                    cur1=cur1->next;
                }
            }
            cur1->next=new ListNode(carry);
        }
        return len1>len2 ? l1:l2;
    }
};