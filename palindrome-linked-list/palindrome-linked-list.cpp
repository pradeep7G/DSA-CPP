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
    bool isPalindrome(ListNode* head) {
        //find mid compare , reverse and return;
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        bool flag=true;
        if(fast==NULL){
            flag=false;
        }
        ListNode* reverse=slow->next;
        slow->next=NULL;
        ListNode* cur=reverse;
        ListNode* prev=NULL;
        while(cur){
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        ListNode *l1=head,*l2=prev;
        bool ispal=false;
        while(l1 && l2){
            if(l1->val != l2->val)
                return false;
            l1=l1->next;l2=l2->next;
        }
        return true;
    }
};