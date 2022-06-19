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
    //TreeNode* deletekey(TreeNode* root,int key){
        // if(root==NULL)
        //     return NULL;
        //  if(root->val > key){
        //     root->left=deletekey(root->left,key);
        // }
        // else if(root->val < key){
        //     root->right = deletekey(root->right,key);
        // }
        // if(root->val==key){
        //     TreeNode* todelete=root;
        //     if(!root->right || !root->left){
        //         root=root->left?root->left:root->right;
        //     }
        //     else{
        //         TreeNode* cur=root->right;
        //         TreeNode* par=root;
        //         while(cur->left){
        //             par=cur;
        //             cur=cur->left;
        //         }
        //         root->val=cur->val;
        //         if(par->left==cur)par->left=cur->right;
        //         else{
        //             par->right=cur->right;
        //         }
        //         todelete=cur;
        //     }
        //     delete todelete;
        // }
        //     return root;
    //}
    TreeNode* deletekey(TreeNode* root,int key){
        if(!root)
            return NULL;
        if(root->val==key){
            TreeNode *todelete=root;
            if(!root->right || !root->left){
                root=root->left?root->left:root->right;
            }
            else{
                TreeNode* par=root;
                TreeNode* cur=root->right;
                while(cur->left){
                    par=cur;
                    cur=cur->left;
                }
                root->val=cur->val;
                if(par->left==cur){
                    par->left=cur->right;
                }
                else{
                    par->right=cur->right;
                }
                todelete=cur;
            }
            delete todelete;
        }
        else if(root->val > key){
            root->left=deletekey(root->left,key);
        }
        else
        {
            root->right=deletekey(root->right,key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletekey(root,key);
    }
};