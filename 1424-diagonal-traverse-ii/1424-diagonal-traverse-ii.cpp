class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        //main idea is each diagonal elements one thing common about their indices, indices sum is same along the diagonal for each diagonal!! this trick is also used in NQueens Remember!!
        map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for(auto i:mp){
            res.insert(res.end(),i.second.rbegin(),i.second.rend());
        }
        return res;
    }
};