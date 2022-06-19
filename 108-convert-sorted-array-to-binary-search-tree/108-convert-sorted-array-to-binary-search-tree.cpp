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
    TreeNode* construct(vector<int> &nums,int left,int right){
        if(left>right)
            return NULL;
        int mid=left+(right-left+1)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=construct(nums,left,mid-1);
        root->right=construct(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        int len=nums.size();
        return construct(nums,0,nums.size()-1);
    }
};