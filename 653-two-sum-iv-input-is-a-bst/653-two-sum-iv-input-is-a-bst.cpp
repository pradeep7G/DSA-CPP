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
    unordered_map<int,bool> mp;
    bool twosum(TreeNode *root,int k){
        if(!root)
            return false;
        if(mp[k-root->val]){
            return true;
        }
        mp[root->val]=true;
        return twosum(root->left,k) || twosum(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return twosum(root,k);
    }
};