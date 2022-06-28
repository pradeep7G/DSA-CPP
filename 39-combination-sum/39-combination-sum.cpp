class Solution {
public:
    vector<vector<int>> res;
    vector<int> sol;
    void solve(int index,int sum,int target,vector<int> &nums){
        if(index>nums.size())
            return ;
         if(sum==target)
        {
            res.push_back(sol);
            return ;
        }
        if(sum>target || index==nums.size())
            return ;
        sol.push_back(nums[index]);
        solve(index,sum+nums[index],target,nums);
        sol.pop_back();
        solve(index+1,sum,target,nums);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        sol.clear();
        solve(0,0,target,candidates);
        return res;
    }
};