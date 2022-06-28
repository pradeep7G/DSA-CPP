class Solution {
public:
    //take not take
    vector<int> subset;
    vector<vector<int>> res;
    void generate(int i,vector<int> &nums){
        if(i==nums.size())
        {
            res.push_back(subset);
            return ;
        }
        //take
        subset.push_back(nums[i]);
        generate(i+1,nums);
        //not take
        subset.pop_back();
        int index=upper_bound(begin(nums),end(nums),nums[i])-nums.begin();
        generate(index,nums);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums),end(nums));
        res.clear();
        subset.clear();
        generate(0,nums);
        return res;
    }
};