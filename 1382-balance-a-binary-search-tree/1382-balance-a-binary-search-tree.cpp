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
    unordered_map<int,TreeNode *> mp;
    void inorder(TreeNode* root,vector<int> &sortedbst){
        if(!root)
            return ;
        inorder(root->left,sortedbst);
        sortedbst.push_back(root->val);
        mp[root->val]=root;
        inorder(root->right,sortedbst);
    }
    TreeNode *balancedbst(int start,int end,vector<int> &sortedbst){
        if(start>end)
            return NULL;
        int mid=start+(end-start+1)/2;
        TreeNode *root=mp[sortedbst[mid]];
        root->left=NULL;
        root->right=NULL;
        root->left=balancedbst(start,mid-1,sortedbst);
        root->right=balancedbst(mid+1,end,sortedbst);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // 1,2,3,4
        vector<int> sortedbst;
        mp.clear();
        inorder(root,sortedbst);
        int start=0,end=sortedbst.size()-1;
        return balancedbst(start,end,sortedbst);
    }
};