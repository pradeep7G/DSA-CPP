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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,pair<int,int>>>> mp;
        queue<pair<TreeNode *,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            auto node=top.first;
            auto coords=top.second;
            mp[coords.second].push_back({node->val,coords});
            if(node->left){
                q.push({node->left,{coords.first+1,coords.second-1}});
            }
            if(node->right){
                q.push({node->right,{coords.first+1,coords.second+1}});
            }
        }
        vector<vector<int>> res;
        for(auto m:mp){
            vector<pair<int,pair<int,int>>> index;
            for(auto i:m.second){
                index.push_back(i);
            }
            sort(begin(index),end(index),[&](auto a,auto b){
               auto first=a.second,second=b.second;
               if(first.first==second.first && first.second==second.second)
                   return a.first < b.first;
               if(first.second < second.second)
                   return true;
               else if(first.second>second.second)
                   return false;
               else if(first.first < second.first)
                   return true;
                return false;
            });
            vector<int> ordered;
            for(auto i:index)
            ordered.push_back(i.first);
            res.push_back(ordered);
        }
        return res;
    }
};