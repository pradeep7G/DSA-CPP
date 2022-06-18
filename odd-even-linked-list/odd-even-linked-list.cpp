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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd=new ListNode(-1);
        ListNode *even=new ListNode(-1);
        ListNode *oddtrav=odd,*eventrav=even;
        ListNode *cur=head;
        int len=1;
        while(cur){
            if(len % 2 == 0){
                eventrav->next=cur;
                eventrav=eventrav->next;
            }
            else{
                oddtrav->next=cur;
                oddtrav=oddtrav->next;
            }
            len++;
            cur=cur->next;
        }
        eventrav->next=NULL;
        if(odd->next==NULL)
            return even->next;
        else if(even->next==NULL)
            return odd->next;
        else{
            oddtrav->next=even->next;
            return odd->next;
        }
    }
};