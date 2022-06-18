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
    ListNode *reverse(ListNode *head){
        ListNode *prev=NULL,*cur=head;
        while(cur){
            ListNode *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
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
        cur1=len1>len2? l1:l2;
        cur2=len1>len2? l2:l1;
        int carry=0;
        cur1=reverse(cur1);
        cur2=reverse(cur2);
        
        ListNode *trav1=cur1,*trav2=cur2;
        ListNode *last=NULL;
        while(trav1 && trav2){
            int digit=(trav1->val + trav2->val + carry);
            trav1->val=digit%10;
            carry=digit/10;
            if(trav1->next==NULL)
                last=trav1;
            trav1=trav1->next;
            trav2=trav2->next;
        }
        if(trav1==NULL){
            if(carry){
                ListNode *newnode=new ListNode(carry);
                last->next=newnode;
                carry=0;
            }
        }
        while(trav1){
            if(carry==0)
                break;
            if(trav1->next==NULL)
                last=trav1;
            int digit=(trav1->val + carry);
            trav1->val=digit%10;
            carry=digit/10;
            trav1=trav1->next;
        }
        if(carry){
            last->next=new ListNode(carry);
        }
        cur1=reverse(cur1);
        return cur1;
    }
};