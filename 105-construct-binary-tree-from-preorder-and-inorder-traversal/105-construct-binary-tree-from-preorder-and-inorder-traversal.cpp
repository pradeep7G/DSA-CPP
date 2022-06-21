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
    unordered_map<int,int> mp;
    TreeNode* recover_tree(int left,int right,unordered_map<int,int> &mp,vector<int> &preorder,int &preindex){
        if(left>right || preindex>=preorder.size())
            return NULL;
        TreeNode* root=new TreeNode(preorder[preindex]);
        int index=mp[preorder[preindex]];
        preindex++;
        root->left=recover_tree(left,index-1,mp,preorder,preindex);
        root->right=recover_tree(index+1,right,mp,preorder,preindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        int left=0,right=inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preindex=0;
        return recover_tree(left,right,mp,preorder,preindex);
    }
};