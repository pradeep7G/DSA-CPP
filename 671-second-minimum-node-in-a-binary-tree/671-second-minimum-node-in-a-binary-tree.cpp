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
    int secondmin(TreeNode *root,int first){
        if(!root)
            return -1;
        if(root->val!=first)
            return root->val;
        int l=secondmin(root->left,first);
        int r=secondmin(root->right,first);
        if(l==-1)
            return r;
        if(r==-1)
            return l;
        return min(l,r);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        return secondmin(root,root->val);
    }
};