/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *lowestcommonancestor(TreeNode *root,TreeNode* p,TreeNode *q){
        // if(!root)
        //     return NULL;
        // if(root==p || root==q){
        //     return root;
        // }
        // TreeNode* leftsubtree=lowestcommonancestor(root->left,p,q);
        // TreeNode* rightsubtree=lowestcommonancestor(root->right,p,q);
        // if(leftsubtree && rightsubtree)
        //     return root;
        // return leftsubtree!=NULL?leftsubtree:rightsubtree;
        if(!root)
            return NULL;
        if(p->val < root->val && q->val < root->val){
           return lowestcommonancestor(root->left,p,q);
        }
        else if(p->val > root->val && q->val > root->val){
           return lowestcommonancestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        return lowestcommonancestor(root,p,q);
    }
};