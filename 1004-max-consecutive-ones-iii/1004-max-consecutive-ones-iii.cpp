class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int left=0,right=0,n=nums.size();
        int ones=0;
        for(;right<n;right++){
            if(nums[right]==1)
                ones++;
            while(right-left+1-ones>k){
                ones-=nums[left++];
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};