class Solution {
public:
    vector<vector<int>> res;
    void solve(int i,vector<int> &nums){
        if(i>=nums.size())
        {
            res.push_back(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            solve(i+1,nums);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        solve(0,nums);
        return res;
    }
};