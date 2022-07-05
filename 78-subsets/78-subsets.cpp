class Solution {
public:
    vector<vector<int>> res;
    void dfs(int i,int n,vector<int> &nums,vector<int> &cur){
        if(i>=n){
            res.push_back(cur);
            return ;
        }
        //take
        cur.push_back(nums[i]);
        dfs(i+1,n,nums,cur);
        cur.pop_back();
        //not take
        dfs(i+1,n,nums,cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //Both bfs and dfs
        int n=nums.size();
        res.clear();
        //dfs
        vector<int> cur;
        dfs(0,n,nums,cur);
        return res;
    }
};