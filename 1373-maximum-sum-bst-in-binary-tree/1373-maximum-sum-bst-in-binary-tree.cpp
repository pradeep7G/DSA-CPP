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
    vector<int> maxsumbst(TreeNode *root){
        if(!root){
           return {1,0,INT_MAX,INT_MIN};
        }
        if(root->left==NULL && root->right==NULL){
            return {1,root->val,root->val,root->val};
        }
        auto l=maxsumbst(root->left);
        auto r=maxsumbst(root->right);
        if(l[0] && r[0]){
            if(l[3] < root->val && root->val < r[2]){
                ans=max({ans,l[1],r[1]});
                int sum=root->val + l[1]+r[1];
                ans=max(ans,sum);
                return {1,sum,min(l[2],root->val),max(r[3],root->val)};
            }
        }
        ans=max({ans,l[1],r[1]});
        return {0,max(l[1],r[1]),0,0};
    }
    int maxSumBST(TreeNode* root) {
        ans=INT_MIN;
        auto res=maxsumbst(root);
        if(res[1]<0)
            return 0;
        return ans;
    }
};