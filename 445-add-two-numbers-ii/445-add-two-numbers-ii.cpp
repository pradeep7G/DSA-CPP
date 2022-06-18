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
    void solve(ListNode *cur1,ListNode *cur2,int &carry){
        if(cur1==NULL || cur2==NULL)
            return ;
        solve(cur1->next,cur2->next,carry);
        int digit=(cur1->val + cur2->val + carry);
        cur1->val=digit%10;
        carry=digit/10;
    }
    void extra(ListNode *l,int &carry,int cnt){
        if(!l || cnt==0)
            return ;
        extra(l->next,carry,cnt-1);
        int digit=l->val+carry;
        l->val=digit%10;
        carry=digit/10;
    }
    ListNode *withoutreverse(ListNode *l1,ListNode *l2){
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
        int diff=abs(len1-len2);
        while(diff--){
            cur1=cur1->next;
        }
        solve(cur1,cur2,carry);
        cur1=len1>len2? l1:l2;
        cur2=len1>len2? l2:l1;
        diff=abs(len1-len2);
        extra(cur1,carry,diff);
        if(carry){
            ListNode *newNode=new ListNode(carry);
            newNode->next=cur1;
            return newNode;
        }
        return cur1;
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
        return withoutreverse(l1,l2);
//         cur1=reverse(cur1);
//         cur2=reverse(cur2);
        
//         ListNode *trav1=cur1,*trav2=cur2;
//         ListNode *last=NULL;
//         while(trav1 && trav2){
//             int digit=(trav1->val + trav2->val + carry);
//             trav1->val=digit%10;
//             carry=digit/10;
//             if(trav1->next==NULL)
//                 last=trav1;
//             trav1=trav1->next;
//             trav2=trav2->next;
//         }
//         if(trav1==NULL){
//             if(carry){
//                 ListNode *newnode=new ListNode(carry);
//                 last->next=newnode;
//                 carry=0;
//             }
//         }
//         while(trav1){
//             if(carry==0)
//                 break;
//             if(trav1->next==NULL)
//                 last=trav1;
//             int digit=(trav1->val + carry);
//             trav1->val=digit%10;
//             carry=digit/10;
//             trav1=trav1->next;
//         }
//         if(carry){
//             last->next=new ListNode(carry);
//         }
//         cur1=reverse(cur1);
//         return cur1;
        
        //Follow up, do it without reversing the linked lists;
    }
};