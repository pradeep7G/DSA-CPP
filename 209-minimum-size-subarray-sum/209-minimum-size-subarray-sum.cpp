class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0,ans=INT_MAX,n=nums.size(),sum=0;
        for(end=0;end<n; end++)
        {
            sum+=nums[end];
            if(sum>=target)
            {
                while(sum>=target)
                {
                    ans=min(ans,end-start+1);
                    sum-=nums[start];
                    start++;
                }
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};