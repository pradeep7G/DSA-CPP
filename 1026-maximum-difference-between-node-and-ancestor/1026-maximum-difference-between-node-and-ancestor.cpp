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
    vector<int> findmaxdiff(TreeNode *root,int &ans){
        if(!root){
            return {INT_MAX,INT_MIN};
        }
        vector<int> left=findmaxdiff(root->left,ans);
        vector<int> right=findmaxdiff(root->right,ans);
        auto curmin=min({root->val,left[0],right[0]});
        auto curmax=max({root->val,left[1],right[1]});
        ans=max({ans,abs(root->val-curmax),abs(root->val-curmin)});
        return {curmin,curmax};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        auto res=findmaxdiff(root,ans);
        return ans;
    }
};