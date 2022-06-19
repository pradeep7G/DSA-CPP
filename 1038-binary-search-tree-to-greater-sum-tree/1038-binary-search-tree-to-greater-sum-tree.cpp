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
    void solve(TreeNode* root,int &sum){
        if(!root)
            return ;
        solve(root->right,sum);
        int tmp=root->val;
        root->val=root->val+sum;
        sum+=tmp;;
        solve(root->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return root;
    }
};