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
//     ListNode *reverseKgroups(ListNode *head,int k,int lenofll){
//         if(!head)
//             return NULL;
//         if(lenofll<k)
//             return head;
//         ListNode *cur=head,*prev=NULL,*next=NULL;
//         int count=0;
//         while(cur!=NULL && count<k){
//             next=cur->next;
//             cur->next=prev;
//             prev=cur;
//             cur=next;
//             count++;
//         }
        
//         if(next!=NULL && lenofll>=k)
//             head->next=reverseKgroups(next,k,lenofll-k);
//         return prev;
//     }
    ListNode *reverse_in_kGroups(ListNode *head,int k,int len){
        if(!head)
            return NULL;
        if(len < k){
            return head;
        }
        ListNode *cur=head,*prev=NULL,*next=NULL;
        int count=0;
        while(count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        if(next!=NULL && len-k>=0)
            head->next=reverse_in_kGroups(next,k,len-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)
            return head;
        ListNode *cur=head;
        int len=0;
        while(cur){
            cur=cur->next;
            len++;
        }
        return reverse_in_kGroups(head,k,len);
        // ListNode *dummy=new ListNode();
        // //do for the first group
        // ListNode *prev=NULL,*cur=head,*link=head,*link2;
        // int cnt=k;
        // for(int i=0;i<cnt;i++){
        //     ListNode *temp=cur->next;
        //     cur->next=prev;
        //     prev=cur;
        //     cur=temp;
        // }
        // dummy->next=prev;
        // //do for the rest of the groups
        // lenofll-=k;
        // while(lenofll>=k){
        //     prev=NULL,cur=cur;
        //     link2=cur;
        //     for(int i=0;i<cnt;i++){
        //         ListNode *temp=cur->next;
        //         cur->next=prev;
        //         prev=cur;
        //         cur=temp;
        //     }
        //     lenofll-=k;
        //     link->next=prev;
        //     link=link2;
        // }
        // if(lenofll!=0 && lenofll<k)
        //     link->next=cur;
        // return dummy->next;
    }
};