class Solution {
public:
    vector<vector<int>> res;
    vector<int> sol;
    void solve(int index,vector<int> &nums,int target){
        if(index>nums.size() || target<0)
            return ;
        if(target==0){
            res.push_back(sol);
            return ;
        }
        if(target<0 || index==nums.size())
            return ;
        sol.push_back(nums[index]);
        solve(index+1,nums,target-nums[index]);
        sol.pop_back();
        int idx=upper_bound(begin(nums),end(nums),nums[index])-begin(nums);
        solve(idx,nums,target);
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sol.clear();
        sort(begin(candidates),end(candidates));
        solve(0,candidates,target);
        return res;
    }
};