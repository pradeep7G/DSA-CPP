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
    unordered_map<TreeNode *,int> mp;
    TreeNode *findlca(TreeNode *root){
        if(!root)
            return NULL;
        int l=countdepths(root->left);
        int r=countdepths(root->right);
        if(l==r){
            return root;
        }
        else if(l<r){
            return findlca(root->right);
        }
        else
        {
            return findlca(root->left);
        }
    }
    int countdepths(TreeNode* root){
        if(!root)
            return 0;
        if(mp.count(root)==0){
            mp[root]=1+(max(countdepths(root->left),countdepths(root->right)));
        }
        return mp[root];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // find if the left subtree and right subtree contains deepest leaves then the root will be lca;
        mp.clear();
       return findlca(root);
    }
};