class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int maxSum=0;int ans=-10000000;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(maxSum+nums[i] <= 0)
        //     {   maxSum=0;
        //         ans=max(ans,nums[i]);
        //     }
        //     else
        //     {
        //         maxSum=maxSum+nums[i];
        //         ans=max(ans,maxSum);
        //     }
        // }
        // return ans;
        
        int maxsum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxsum+=nums[i];
            ans=max(ans,maxsum);
            if(maxsum <= 0){
                maxsum=0;
            }
        }
        return ans;
    }
};