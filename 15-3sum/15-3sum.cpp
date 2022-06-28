class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int i=0;
        vector<vector<int>> res;
        while(i<n-2){
            int left=i+1,right=n-1;
            while(left<right){
                if(left>=right)
                    break;
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<n-1 && left<right && nums[left]==nums[left+1])
                        left++;
                    while(right>=1 && nums[right]==nums[right-1])
                        right--;
                        left++,right--;
                }
                else if(sum<0){
                    left++;
                }
                else
                    right--;
            }
            while(i<n-2 && nums[i]==nums[i+1])
                i++;
            i++;
        }
        return res;
    }
};