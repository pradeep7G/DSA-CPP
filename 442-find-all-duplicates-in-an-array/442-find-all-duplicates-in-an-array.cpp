class Solution {
public:
    vector<int> solve(vector<int> &nums){
        vector<int> res;
        int i=0;
        int n=nums.size();
        //cyclic sort
        while(i<n){
            while(nums[i]!=i+1 and nums[nums[i]-1]!=nums[i])
                swap(nums[nums[i]-1],nums[i]);
            i++;
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                res.push_back(nums[i]);
        return res;
    }
    vector<int> findDuplicates(vector<int>& nums) {
        //cyclic sort
        return solve(nums);
        vector<int> res;
        int i=0;
        int n=nums.size();
        //-ve marking
        // for(int i=0;i<n;i++){
        //     if(nums[abs(nums[i])-1]<0)
        //         res.push_back(abs(nums[i]));
        //     else
        //         nums[abs(nums[i])-1]*=-1;
        // }
        //cyclic sort
        // while(i<n){
        //     while(nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
        //         swap(nums[i],nums[nums[i]-1]);
        //     }
        //     i++;
        // }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                res.push_back(nums[i]);
        return res;
    }
};