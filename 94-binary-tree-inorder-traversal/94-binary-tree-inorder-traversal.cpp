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
    vector<int> morrisTraversal(TreeNode* root){
        vector<int> inorder;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                //create thread
                TreeNode* prev=cur->left;
                while(prev->right!=NULL && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;//connect the thread
                    cur=cur->left;//Now move left;
                }
                else { //if we completed left subtree we again came to the root and we need to remove the thread and add the root to the inorder traversal as we recognized the loop i.e prev->right==cur, remove loop, add cur to inorder, move right;
                    prev->right=NULL;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //Iterative TC:O(N),SC:O(N)
        //can you do traversal in O(1)? Morris traversal..
        return morrisTraversal(root);
        stack<TreeNode *> st;
        vector<int> inorder;
        TreeNode* cur=root;
        while(!st.empty() || cur!=NULL){
            if(cur!=NULL){
                //add curr to the stack and explore left.
                st.push(cur);
                cur=cur->left;
            }
            else{
                //take the top of the stack and add it the solution, and explore right.
                cur=st.top();
                st.pop();
                inorder.push_back(cur->val);
                cur=cur->right;
            }
        }
        return inorder;
    }
};