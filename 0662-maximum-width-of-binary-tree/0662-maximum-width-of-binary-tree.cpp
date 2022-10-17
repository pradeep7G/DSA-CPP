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
    typedef unsigned long long ull;
    int solve(TreeNode *root){
        if(!root)
            return 0;
        queue<pair<TreeNode *,ull>> q;
        q.push({root,0});
        ull ans=1;
        while(!q.empty()){
            ull l=-1,r=-1;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto front=q.front();
                q.pop();
                TreeNode* node=front.first;
                ull idx=front.second;
                if(i==0)
                    l=idx;
                else if(i==sz-1)
                    r=idx;
                if(node->left)
                    q.push(make_pair(node->left,2*idx + 1));
                if(node->right)
                    q.push(make_pair(node->right,2*idx + 2));
            }
            if(l==-1 || r==-1)
                continue;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
    int widthOfBinaryTree(TreeNode* root) {
        //can do bfs, but can we do it dfs?
        return solve(root);
        if(!root)
            return 0;
        queue<pair<TreeNode *,unsigned long long>> q;
        q.push({root,0});
        unsigned long long ans=1;
        while(!q.empty()){
            unsigned long long l=-1,r=-1;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                auto node=front.first;
                auto index=front.second;
                if(i==0)
                    l=index;
                else if(i==size-1)
                    r=index;
                if(node->left){
                    q.push({node->left,2*index+1});
                }
                if(node->right){
                    q.push({node->right,2*index+2});
                }
            }
            if(l==-1 || r==-1)
                continue;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};