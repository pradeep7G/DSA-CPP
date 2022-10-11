class Solution {
public:
    vector<vector<int>> res;
    void solve_p(int idx,vector<int> &nums){
        if(idx>=size(nums)){
            res.push_back(nums);
            return ;
        }
        for(int j=idx;j<size(nums);j++){
            swap(nums[j],nums[idx]);
            solve(idx+1,nums);
            swap(nums[j],nums[idx]);
        }
    }
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
    vector<vector<int>> bfs(vector<int> &nums){
        vector<vector<int>> res;
        queue<vector<int>>perms;
        perms.push(vector<int>());
        for(int i=0;i<size(nums);i++){
            int n=perms.size();
            for(int j=0;j<n;j++){
                vector<int> oldPerm=perms.front();
                perms.pop();
                for(int k=0;k<=size(oldPerm);k++){
                    vector<int> newPerm(oldPerm);
                    newPerm.insert(newPerm.begin()+k,nums[i]);
                    if(size(oldPerm)==size(newPerm)){
                        res.push_back(newPerm);
                    }
                    else{
                        perms.push(newPerm);
                    }
                }
            }
        }
        return res;
    }
    vector<vector<int>> bfs_p(vector<int> &nums){
        vector<vector<int>> res;
        queue<vector<int>> permutations;
        permutations.push(vector<int>());
        for(int i=0;i<nums.size();i++){
            int n=permutations.size();
            for(int j=0;j<n;j++){
                vector<int> old_permutation=permutations.front();
                permutations.pop();
                for(int k=0;k<=old_permutation.size();k++){
                    vector<int> new_permutation(old_permutation);
                    new_permutation.insert(new_permutation.begin()+k,nums[i]);
                    if(new_permutation.size()==nums.size())
                        res.push_back(new_permutation);
                    else
                        permutations.push(new_permutation);
                }
            }
        }
        return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        return bfs_p(nums);
        solve_p(0,nums);
        return res;
    }
};