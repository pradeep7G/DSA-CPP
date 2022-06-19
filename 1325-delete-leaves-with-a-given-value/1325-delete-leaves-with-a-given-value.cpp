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
    TreeNode* deleteleafs(TreeNode * &root,int key){
        if(!root)
            return NULL;
        if(!root->left && !root->right && root->val==key){
            root=NULL;
            return root;
        }
        if(root)
        deleteleafs(root->left,key);
        if(root && root->val==key && root->left==NULL && root->right==NULL)
        {
             root=NULL;
            return root;
        }
        if(root)
        deleteleafs(root->right,key);
        if(root && root->val==key && root->left==NULL && root->right==NULL)
        {
             root=NULL;
            return root;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* res=deleteleafs(root,target);
        return res;
    }
};