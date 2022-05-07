class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int m=abs(nums[i])-1;
            if(nums[m]<0)
                ans.push_back(abs(nums[i]));
            nums[m]=-nums[m];
        }
        for(auto x:nums)cout<<x<<" ";cout<<"\n";
       return ans;
    }
};