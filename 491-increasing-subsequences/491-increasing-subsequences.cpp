class Solution {
public:
    void solve(int ind,int n,vector<int> &nums,vector<int> &choose,vector<vector<int>> &res){
        if(choose.size()>1)
            res.push_back(choose);
        unordered_set<int> hash;
        for(int pos=ind;pos<n;pos++){
            if((choose.empty() || (choose.back())<=nums[pos]) && hash.find(nums[pos])==hash.end()){
                choose.push_back(nums[pos]);
                solve(pos+1,n,nums,choose,res);
                choose.pop_back();
                hash.insert(nums[pos]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> choose;
        int n=nums.size();
        solve(0,n,nums,choose,res);
        return res;
    }
};