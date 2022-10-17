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
    void solve1(TreeNode* root,int &k,int &ans){
        if(!root){
            return ;
        }
        solve1(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
            return ;
        }
        solve1(root->right,k,ans);
    }
    int solve2(TreeNode* root,int k){
        TreeNode* p=root;
        stack<TreeNode *> st;
        while(p || !st.empty()){
            if(p){
                st.push(p);
                p=p->left;
            }
            else{
                p=st.top();
                st.pop();
                k--;
                if(k==0){
                    return p->val;
                }
                p=p->right;
            }
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        // solve1(root,k,ans);
        return solve2(root,k);
        // return ans;
    }
};