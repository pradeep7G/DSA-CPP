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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a--,b++;
        ListNode* cur=list1;
        int i=0;
        ListNode *start=NULL,*end=NULL;
        while(cur){
            if(i==a){
                start=cur;
            }
            else if(i==b){
                end=cur;
            }
            i++;
            cur=cur->next;
        }
        cur=list2;
        while(cur->next){
            cur=cur->next;
        }
        if(start && end){
            start->next=list2;
            cur->next=end;
        }
        return list1;
    }
};