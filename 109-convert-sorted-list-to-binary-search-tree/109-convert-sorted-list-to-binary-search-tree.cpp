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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head,ListNode* end){
        ListNode *slow=head,*fast=head;
        ListNode *prev=NULL;
        while(fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    TreeNode* construct(ListNode* root,ListNode* end){
        if(root==end)
            return NULL;
        if(root->next==end){
            return new TreeNode(root->val);
        }
        ListNode* mid=findMid(root,end);
        TreeNode* treeRoot=new TreeNode(mid->val);
        treeRoot->left=construct(root,mid);
        treeRoot->right=construct(mid->next,end);
        return treeRoot;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // 0 --> 1 --> 2 --> 3 --> 4 --> 5 --> 6 --> NULL
        return construct(head,NULL);
    }
};