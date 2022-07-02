class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0,n=nums.size(),ans=0,ones=0;
        for(;right<n;right++){
            if(nums[right]==1)
                ones++;
            while(right-left+1-ones>1){
                ones-=(nums[left++]==1);
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};