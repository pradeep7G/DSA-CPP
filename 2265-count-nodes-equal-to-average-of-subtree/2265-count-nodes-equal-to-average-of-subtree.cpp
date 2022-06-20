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
    int count=0;
    vector<int> averagesubtrees(TreeNode *root){
        if(!root){
            return {0,0};
        }
        auto left=averagesubtrees(root->left);
        auto right=averagesubtrees(root->right);
        int avg=(left[0]+right[0]+root->val)/(left[1]+right[1]+1);
        if(avg==root->val)
            count++;
        return {left[0]+right[0]+root->val,left[1]+right[1]+1};
    }
    int averageOfSubtree(TreeNode* root) {
        count=0;
        auto res=averagesubtrees(root);
        return count;
    }
};