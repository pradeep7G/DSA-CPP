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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)
            return {-1,-1};
        ListNode *pre=head,*cur=pre->next,*nxt=cur->next;
        vector<int> criticalPoints;
        int i=1;
        while(nxt){
            if((cur->val>pre->val && cur->val>nxt->val) || (cur->val<pre->val && cur->val<nxt->val)){
                criticalPoints.push_back(i);
            }
            i++;
            pre=pre->next;
            cur=cur->next;
            nxt=nxt->next;
        }
        int n=criticalPoints.size();
        if(n<2)
            return {-1,-1};
        int minDistance=INT_MAX,maxDistance=-1;
        maxDistance=criticalPoints[n-1]-criticalPoints[0];
        for(int i=1;i<n;i++){
            minDistance=min(minDistance,criticalPoints[i]-criticalPoints[i-1]);
        }
        return {minDistance,maxDistance};
    }
};