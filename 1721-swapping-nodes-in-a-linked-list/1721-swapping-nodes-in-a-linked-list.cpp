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
    ListNode* swapNodes(ListNode* head, int k) {
        int i=1;
        ListNode* kthNode=NULL;
        ListNode* kthNodeFromEnd=NULL;
        ListNode* cur=head;
        ListNode* secondPointer=head;
        while(cur){
            if(i==k){
                kthNode=cur;
            }
            if(i<=k)
            {
                i++;
                cur=cur->next;
                continue;
            }
            i++;
            secondPointer=secondPointer->next;
            cur=cur->next;
        }
        swap(secondPointer->val,kthNode->val);
        return head;
    }
};