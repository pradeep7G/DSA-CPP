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
    ListNode* solve(ListNode *head){
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* cur=head;
        int sum=0;//running sum;
        mp[0]=dummy;
        for(;cur;){
            sum+=cur->val;
            if(mp.count(sum)){
                cur=mp[sum]->next;
                int auxSum=sum+cur->val;
                while(auxSum!=sum){
                    mp.erase(auxSum);
                    cur=cur->next;
                    auxSum+=cur->val;
                }
                mp[sum]->next=cur->next;
            }
            else
                mp[sum]=cur;
            cur=cur->next;
        }
        return dummy->next;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        return solve(head);
        unordered_map<int,ListNode *> mp;
        ListNode* dummy=new ListNode(-1e5);
        dummy->next=head;
        ListNode* cur=dummy;
        int sum=0;
        for(;cur;){
            sum+=cur->val;
            if(mp.find(sum)!=mp.end()){
                cur=mp[sum]->next;
                int auxSum=sum+cur->val;
                //removing nodes
                while(auxSum!=sum){
                    mp.erase(auxSum);
                    cur=cur->next;
                    auxSum+=cur->val;
                }
                mp[sum]->next=cur->next;
            }
            else
             mp[sum]=cur;
            cur=cur->next;
        }
        return dummy->next;
    }
};