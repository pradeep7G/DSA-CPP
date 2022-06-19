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
    bool solve(TreeNode* root,int sum){
        if(!root)
            return false;
        if(root->val==sum && root->left==NULL && root->right==NULL){
            return true;
        }
        return solve(root->left,sum-root->val) || solve(root->right,sum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return solve(root,targetSum);
    }
};