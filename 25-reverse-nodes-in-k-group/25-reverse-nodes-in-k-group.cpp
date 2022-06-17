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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
            return head;
        int lenofll=0;
        ListNode* trav=head;
        while(trav){
            trav=trav->next;
            lenofll++;
        }
        ListNode *dummy=new ListNode();
        
        //do for the first group
        ListNode *prev=NULL,*cur=head,*link=head,*link2;
        int cnt=k;
        for(int i=0;i<cnt;i++){
            ListNode *temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        dummy->next=prev;
        //do for the rest of the groups
        lenofll-=k;
        while(lenofll>=k){
            prev=NULL,cur=cur;
            link2=cur;
            for(int i=0;i<cnt;i++){
                ListNode *temp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=temp;
            }
            lenofll-=k;
            link->next=prev;
            link=link2;
        }
        if(lenofll!=0 && lenofll<k)
            link->next=cur;
        return dummy->next;
    }
};