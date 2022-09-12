class Solution {
public:
    int solve(vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] and dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] and dp[i]==1+dp[j]){
                    cnt[i]+=cnt[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                res+=cnt[i];
            }
        }
        return res;
    }
    int findNumberOfLIS(vector<int>& nums) {
        //no.of longest increasing subsequence , we know how to calculate no.of longest subsequence, but how to calculate total count, add extra conditions for the problem lcs extrapolate it to accomodate the need  
        //if the current i, find add to a new prev lis, we just copy no.of lis's possible with prev_lis as when current element i added to them it will be the same, we repeat this as long as we find a new potential lis
        //if we the prev lis has the same potential length of lcs as current i, current i lcs can also be part of the same set of lis's with length lcs_i_length-1, then we add no.of lis possible with them to the current i lis; REFER Striver's blog/youtube video to understand AGAIN!!
        return solve(nums);
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i] && dp[i]==1+dp[j]){
                    cnt[i]+=cnt[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)
                res+=cnt[i];
        }
        return res;
    }
};