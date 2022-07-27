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
    vector<int> v;
    void inorder(TreeNode *root){
        if(!root)
            return ;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void recovertree(TreeNode *root,int &index){
        if(!root)
            return ;
        recovertree(root->left,index);
        root->val=v[index];
        index++;
        recovertree(root->right,index);
    }
    void getNodes(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &second){
        if(!root)
            return ;
        getNodes(root->left,prev,first,second);
        if(prev!=NULL && prev->val > root->val){
            //found a misplaced node,
            //what if the misplaced nodes are consecutive,if the misplaced nodes are consecutive the above prev->val > root->data might doesn't hold for other values right, so i just store second node also now!
            if(first==NULL){
                first=prev;
            }
            second=root;
        }
        prev=root;
        getNodes(root->right,prev,first,second);
    }
    void recoverTree(TreeNode* root) {
        //TC:O(N),SC:O(N)
        //Can we do better?
        /*
        v.clear();
        inorder(root);
        sort(v.begin(),v.end());
        int index=0;
        recovertree(root,index);
        */
        //approach-2 do inorder traversal, just store the two misplced nodes refereces and swap values.. hmm sound's correct..
        TreeNode *prev=NULL,*first=NULL,*second=NULL;
        getNodes(root,prev,first,second);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
};