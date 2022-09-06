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
    unordered_map<TreeNode *,TreeNode *> parent;
    unordered_map<int,TreeNode*> idNode;
    int nodes=0;
    int ans=0;
    void parentmap(TreeNode* root){
        if(!root)
            return ;
        nodes++;
        idNode[root->val]=root;
        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]=root;
        }
        parentmap(root->left);
        parentmap(root->right);
    }
    int dfs(TreeNode* root,unordered_map<int,int> &visited){
        if(!root){
            return 1;
        }
        visited[root->val]=1;
        int par=0;
        if(parent[root] && visited[parent[root]->val]==0){
            par=1+dfs(parent[root],visited);
        }
        int left=0;
        if(root->left && visited[root->left->val]==0){
            left=1+dfs(root->left,visited);
        }
        int right=0;
        if(root->right && visited[root->right->val]==0){
            right=1+dfs(root->right,visited);
        }
        return max({par,left,right});
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,int> visited;
        parentmap(root);
        return dfs(idNode[start],visited);
        vector<bool> vis(100005,false);
        parentmap(root);
        queue<TreeNode*> q;
        TreeNode *st=idNode[start];
        q.push(st);
        int cnt=0;
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* front=q.front();
                q.pop();
                if(!front)
                    continue;
                vis[front->val]=true;
                if(front->left)
                {
                    if(!vis[front->left->val]){
                        q.push(front->left);
                        cnt++;
                    }
                }
                if(front->right){
                    if(!vis[front->right->val]){
                        q.push(front->right);
                        cnt++;
                    }
                }
                if(parent[front]){
                    if(!vis[parent[front]->val]){
                        q.push(parent[front]);
                        cnt++;
                    }
                }
            }
            if(!q.empty())
            time++;
        }
        return time;
    }
};