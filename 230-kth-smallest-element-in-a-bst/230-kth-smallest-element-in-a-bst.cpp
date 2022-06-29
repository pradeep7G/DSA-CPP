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
    void kthsmallest(TreeNode* root,int &k,int &ans){
       if(!root)
       {
           return ;
       }
        kthsmallest(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
        }
        kthsmallest(root->right,k,ans);
    }
    int iterative(TreeNode* root,int k){
        TreeNode* p=root;
        stack<TreeNode *> s;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p=p->left;
            }
            p=s.top();
            s.pop();
            k--;
            if(k==0)
                return p->val;
            p=p->right;
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        kthsmallest(root,k,ans);
        return ans;
    }
};