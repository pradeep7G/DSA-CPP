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
    TreeNode* recover_tree(int start,int end,int &postindex,vector<int> &postorder,unordered_map<int,int> &mp){
        if(start>end || postindex>=postorder.size())
            return NULL;
        TreeNode *root=new TreeNode(postorder[postindex]);
        int index=mp[postorder[postindex]];
        postindex++;
        if(start==end)
            return root;
        root->right=recover_tree(index+1,end,postindex,postorder,mp);
        root->left=recover_tree(start,index-1,postindex,postorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int start=0,end=n-1;
        reverse(postorder.begin(),postorder.end());
        int postindex=0;
        return recover_tree(start,end,postindex,postorder,mp);
    }
};