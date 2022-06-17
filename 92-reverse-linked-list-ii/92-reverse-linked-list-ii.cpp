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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode *prev=NULL,*next=NULL,*cur=head;
        int id=1;
        for(int i=1;i<=right;i++){
            if(i==left-1){
                prev=cur;
            }
            else if(i==left){
                int len=right-left+1;
                next=cur;
                ListNode *pre=NULL;
                while(len--){
                    ListNode *temp=cur->next;
                    cur->next=pre;
                    pre=cur;
                    cur=temp;
                }
                if(prev){
                    prev->next=pre;
                }
                next->next=cur;
                if(left==1){
                    return pre;
                }
                else{
                    return head;
                }
            }
            cur=cur->next;
        }
        return NULL;
    }
};