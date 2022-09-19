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
    struct compare{
        bool operator()(pair<int,int> &a,pair<int,int> &b)
        {
            return a.second > b.second;
        }
    };
    unordered_map<int,int> mp;
    //find the subtree sums, store them and their frequencies in the hashmap
    int solve(TreeNode* root){
        if(!root)
            return 0;
        //get sum of the subtree rooted at root;
        int left=solve(root->left);
        int right=solve(root->right);
        int sum=left+root->val+right;
        mp[sum]++;
        return sum;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        int sum=root->val + left + right;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        vector<int> res;
        int maxF=INT_MIN;
        for(auto i:mp){
            maxF=max(maxF,i.second);
        }
        for(auto i:mp){
            if(i.second==maxF){
                res.push_back(i.first);
            }
        }
        return res;
    }
};