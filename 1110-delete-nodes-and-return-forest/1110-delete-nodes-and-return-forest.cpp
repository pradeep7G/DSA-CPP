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
    bool find(TreeNode *root,int key){
        if(!root)
            return false;
        if(root->val==key)
            return true;
        return find(root->left,key) || find(root->right,key);
    }
    TreeNode* deletekey(TreeNode* root,int key,set<TreeNode *> &s){
        if(!root){
            return NULL;
        }
        if(root->val == key){
            if(root->left){
                s.insert(root->left);
            }
            if(root->right){
                s.insert(root->right);
            }
            root=NULL;
            return NULL;
        }
        root->left=deletekey(root->left,key,s);
        root->right=deletekey(root->right,key,s);
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<TreeNode *> s;
        s.insert(root);
        for(auto i:to_delete){
            for(auto x:s){
                if(find(x,i)){
                    auto res=deletekey(x,i,s);
                    if(res)
                    s.insert(res);
                    else{
                        s.erase(x);
                    }
                    break;
                }
            }
        }
        vector<TreeNode *> res;
        for(auto i:s)
        res.push_back(i);
        return res;
    }
};