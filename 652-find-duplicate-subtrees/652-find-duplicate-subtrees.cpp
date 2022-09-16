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
    unordered_map<string,int> mp;
    string solve(TreeNode *root,vector<TreeNode *> &res){
        if(!root)
            return "$";
        string a=solve(root->left,res);
        string b=solve(root->right,res);
        string ret="("+a+to_string(root->val)+b+")";
        if(mp.count(ret))
            if(mp[ret]==1)
                res.push_back(root);
        mp[ret]++;
        return ret;
    }
    string dfs(TreeNode* root,vector<TreeNode *> &res){
        if(!root)
            return "()";
        string a=dfs(root->left,res);
        string b=dfs(root->right,res);
        string ret="("+a+to_string(root->val)+b+")";
        if(mp.find(ret)!=mp.end()){
            if(mp[ret]==1)
            res.push_back(root);
        }
        mp[ret]++;
        return ret;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        vector<TreeNode *> res;
        solve(root,res);
        return res;
    }
};