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
    TreeNode *prunetree(TreeNode* root){
        if(!root)
            return NULL;
        root->left=prunetree(root->left);
        root->right=prunetree(root->right);
        if(root->left==NULL && root->right==NULL && root->val==0){
            root=NULL;
            return root;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode *res=prunetree(root);
        return res;
    }
};