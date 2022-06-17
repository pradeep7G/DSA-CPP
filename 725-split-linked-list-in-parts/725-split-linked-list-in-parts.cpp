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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> v(k);
        ListNode* cur=head;
        int len=0;
        while(cur){
            len++;
            cur=cur->next;
        }
        cur=head;
        int cnt=k;
        for(int i=0;i<k;i++){
            if(len==0)
                continue;
            int nodes=(len%cnt == 0)? len/cnt : (len/cnt)+1;
            ListNode *res=new ListNode(-1);
            ListNode *trav=res;
            while(nodes--){
                trav->next=cur;
                trav=trav->next;
                cur=cur->next;
            }
            trav->next=NULL;
            v[i]=(res->next);
            len-=(len%cnt==0)?len/cnt:(len/cnt)+1;
            cnt--;
        }
        return v;
    }
};