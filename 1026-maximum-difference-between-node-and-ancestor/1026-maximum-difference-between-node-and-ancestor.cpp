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
            return {};
        }
        if(root->left==NULL && root->right==NULL)
        {
            return {root->val,root->val};
        }
        vector<int> left=findmaxdiff(root->left,ans);
        vector<int> right=findmaxdiff(root->right,ans);
        if(left.size()==2){
            ans=max({ans,abs(root->val - left[0]),abs(root->val-left[1])});
        }
        if(right.size()==2){
            ans=max({ans,abs(root->val-right[0]),abs(root->val-right[1])});
        }
        if(left.size()==2 && right.size()==2){
            return {min({left[0],right[0],root->val}),max({left[1],right[1],root->val})};
        }
        else{
            if(left.size()==2){
                return {min(left[0],root->val),max(root->val,left[1])};
            }
            else{
                return {min(right[0],root->val),max(root->val,right[1])};
            }
        }
        return {INT_MAX,INT_MIN};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        auto res=findmaxdiff(root,ans);
        return ans;
    }
};