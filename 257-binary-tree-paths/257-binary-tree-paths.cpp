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
    vector<string> ans;
    void roottoleafpaths(TreeNode* root,string s){
        if(!root)
        {
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s+to_string(root->val));
            return ;
        }
        roottoleafpaths(root->left,s+to_string(root->val)+"->");
        roottoleafpaths(root->right,s+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string s="";
        roottoleafpaths(root,s);
        return ans;
    }
};