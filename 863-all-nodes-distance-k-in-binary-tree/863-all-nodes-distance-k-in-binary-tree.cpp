/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* parent){
        if(!root)
            return ;
        mp[root]=parent;
        getParents(root->left,mp,root);
        getParents(root->right,mp,root);
    }
    void dfs(TreeNode* root,int k,unordered_map<TreeNode*,TreeNode*> &mp,vector<int> &ans,unordered_set<TreeNode *> &vis){
        if(!root || k<0 || vis.count(root))
            return ;
        vis.insert(root);
        if(k==0){
            ans.push_back(root->val);
            return ;
        }
        dfs(root->left,k-1,mp,ans,vis);
        dfs(root->right,k-1,mp,ans,vis);
        dfs(mp[root],k-1,mp,ans,vis);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> childParent;
        vector<int> ans;
        getParents(root,childParent,NULL);
        unordered_set<TreeNode *> visited;
        dfs(target,k,childParent,ans,visited);
        return ans;
    }
};