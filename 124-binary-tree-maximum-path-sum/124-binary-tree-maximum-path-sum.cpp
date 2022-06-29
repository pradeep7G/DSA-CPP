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
    int ans=INT_MIN;
    int maxpathsum(TreeNode* root){
        if(!root)
            return 0;
        int left=max(maxpathsum(root->left),0);
        int right=max(maxpathsum(root->right),0);
        int sum=root->val + left + right;
        ans=max(ans,sum);
        return root->val + max(left,right);
        
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        maxpathsum(root);
        return ans;
    }
};