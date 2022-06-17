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
    ListNode* recursiveLL(ListNode* root,ListNode* prev){
        if(!root){
            return prev;
        }
        ListNode* temp=root->next;
        root->next=prev;
        return recursiveLL(temp,root);
    }
    ListNode* reverseLL(ListNode* root){
        if(!root)
            return NULL;
        ListNode *prev=NULL,*cur=root;
        while(cur){
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        return reverseLL(head);
    }
};