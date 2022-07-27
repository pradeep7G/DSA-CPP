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
    void MorrisInorderTraversal(TreeNode* root,TreeNode* &prev,TreeNode* &first,TreeNode* &second){
       TreeNode* cur=root;
       while(cur){
           if(cur->left==NULL){
                if(prev!=NULL && prev->val > cur->val)
                {
                    if(first==NULL)
                    {
                        first=prev;
                    }
                    second=cur;
                }
                prev=cur;
                cur=cur->right;
           }
           else{
               //create/remove thread
               TreeNode* pre=cur->left;
               while(pre->right && pre->right!=cur)
                   pre=pre->right;
               
               //if thread not exists,create
               if(pre->right==NULL){
                   pre->right=cur;
                   cur=cur->left;
               }
               else{
                   //if thread already exists
                   if(prev!=NULL && prev->val > cur->val)
                    {
                        if(first==NULL)
                        {
                            first=prev;
                        }
                        second=cur;
                    }
                   pre->right=NULL;
                   prev=cur;
                   cur=cur->right;
               }
           }
       }
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return ;
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
        
        //Oh wait!!, it works BUT recursion is not O(1) space right? so how to do in absolute O(1) space? YES!! Morris Inorder Traversal!!
        
        TreeNode *prev=NULL,*first=NULL,*second=NULL;
        MorrisInorderTraversal(root,prev,first,second);
        int tmp=first->val;
        first->val=second->val;
        second->val=tmp;
    }
};