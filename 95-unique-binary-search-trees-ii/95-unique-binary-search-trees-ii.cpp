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
    vector<TreeNode *> find_bst_trees(int start,int end){
        vector<TreeNode*> trees;
        if(start>end){
            trees.push_back(NULL);
            return trees;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftsubtrees=find_bst_trees(start,i-1);
            vector<TreeNode*> rightsubtrees=find_bst_trees(i+1,end);
            for(auto &left:leftsubtrees){
                for(auto &right:rightsubtrees){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0){
            return {};
        }
        return find_bst_trees(1,n);
    }
};