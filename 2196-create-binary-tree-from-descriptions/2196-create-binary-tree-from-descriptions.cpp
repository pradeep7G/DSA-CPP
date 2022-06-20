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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode *> mp;
        unordered_map<int,int> mp2;
        for(auto v:descriptions){
            int parent=v[0],child=v[1];
            int isleft=v[2];
            if(mp.count(parent)==0){
                TreeNode *par=new TreeNode(parent);
                mp[parent]=par;
            }
            if(mp.count(child)==0){
                TreeNode *ch=new TreeNode(child);
                mp[child]=ch;
            }
            mp2[child]=parent;
            if(isleft){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
        }
                   
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            if(mp2[i->first]==0){
                return i->second;
            }
        }
        return NULL;
    }
};