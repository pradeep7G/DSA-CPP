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
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head)
            return {};
        ListNode *cur=head;
        int len=0;
        while(cur){
            cur=cur->next;
            len++;
        }
        vector<int> v(len);
        stack<pair<int,int>> s;
        s.push({0,head->val});
        cur=head->next;
        for(int i=1;i<len && cur;i++){
            while(!s.empty() && cur->val > s.top().second){
                v[s.top().first]=cur->val;
                s.pop();
            }
            s.push({i,cur->val});
            cur=cur->next;
        }
        while(!s.empty()){
            auto p=s.top();
            s.pop();
            v[p.first]=0;
        }
        return v;
    }
};