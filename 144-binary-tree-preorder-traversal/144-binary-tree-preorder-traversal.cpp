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
    vector<int> morrisPreorder(TreeNode* root){
        //TC:O(N),O(1)
        if(!root)
            return {};
        vector<int> preOrder;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                preOrder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right!=NULL && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    preOrder.push_back(cur->val); //before moving to the left, we add cur to preOrder,since root,left,right
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    //if it is inorder traversal we add cur to the inorder,since left,root,right;
                    cur=cur->right;
                }
            }
        }
        return preOrder;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return morrisPreorder(root);
        //Iterative
        if(!root)
            return {};
        stack<TreeNode*> st;
        vector<int> preOrder;
        TreeNode* cur=root;
        st.push(cur);
        while(!st.empty()){
            TreeNode* topNode=st.top();
            st.pop();
            preOrder.push_back(topNode->val);
            if(topNode->right)
                st.push(topNode->right);
            if(topNode->left)
                st.push(topNode->left);
        }
        return preOrder;
    }
};