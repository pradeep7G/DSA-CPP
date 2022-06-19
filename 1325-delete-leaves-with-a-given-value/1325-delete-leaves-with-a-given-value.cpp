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
        root->left=deleteleafs(root->left,key);
        root->right=deleteleafs(root->right,key);
        if(root->val==key && root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* res=deleteleafs(root,target);
        return res;
    }
};