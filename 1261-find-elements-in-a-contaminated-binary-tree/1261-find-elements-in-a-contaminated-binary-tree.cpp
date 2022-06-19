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
class FindElements {
public:
    TreeNode *master=NULL;
    void decontaminate(TreeNode *root,int val=0){
        if(!root)
            return ;
        root->val=val;
        decontaminate(root->right,2*val + 2);
        decontaminate(root->left,2*val + 1);
    }
    FindElements(TreeNode* root) {
        master=root;
        decontaminate(master);
    }
    bool search(int target,TreeNode *root){
          if(!root)
            return false;
        if(root->val == target)
            return true;
        return search(target,root->left) || search(target,root->right);
    }
    bool find(int target) {
        return search(target,master);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */