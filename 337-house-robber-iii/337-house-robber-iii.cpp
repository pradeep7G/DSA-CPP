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
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->val,0};
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        return {root->val+left.second+right.second,max(left.first,left.second)+max(right.first,right.second)};
    }
    int rob(TreeNode* root) {
        pair<int,int> res=solve(root);
        return max(res.first,res.second);
    }
};