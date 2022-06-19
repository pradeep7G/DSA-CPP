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
    int findindex(int left,int right,vector<int> &nums){
        if(left>right)
            return -1;
        int num=nums[left];
        int i=left+1;
        for(i=left+1;i<=right;i++){
            if(nums[i]>num)
                return i;
        }
        return i;
    }
    TreeNode* bstfrompreorder(int left,int right,vector<int> &preorder){
        if(left>right)
            return NULL;
        int index=findindex(left,right,preorder);
        TreeNode *root=new TreeNode(preorder[left]);
        if(left==right)
            return root;
        root->left=bstfrompreorder(left+1,index-1,preorder);
        root->right=bstfrompreorder(index,right,preorder);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        return bstfrompreorder(0,preorder.size()-1,preorder);
    }
};