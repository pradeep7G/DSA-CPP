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
    TreeNode* search(TreeNode *root,int val){
        //searching in a BINARY TREE
        if(!root)
            return NULL;
        if(root->val==val){
            return root;
        }
        TreeNode *left=search(root->left,val);
        TreeNode *right=search(root->right,val);
        if(left && right)
            return root;
        return left!=NULL?left:right;
    }
    TreeNode* searchBst(TreeNode* root,int val){
        if(!root)
            return NULL;
        if(root->val == val)
        {
            return root;
        }
        if(root->val < val){
            return search(root->right,val);
        }
        return search(root->left,val);
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        return searchBst(root,val);
    }
};