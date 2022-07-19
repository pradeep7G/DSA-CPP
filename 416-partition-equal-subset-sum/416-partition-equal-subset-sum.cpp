class Solution {
public:
    int solve(int ind,int n,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==0){
            return nums[0]==target;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        //notTake
        bool notTake=solve(ind-1,n,target,nums,dp);
        //take
        bool take=false;
        if(nums[ind]<=target)
            take=solve(ind-1,n,target-nums[ind],nums,dp);
        return dp[ind][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totSum=accumulate(begin(nums),end(nums),0LL);
        int n=nums.size();
        //s1+s2=totSum && s1=s2 ==> s2=totSum/2;
        if(totSum%2)
            return false;
        vector<vector<int>> dp(n,vector<int>(totSum/2 + 1,-1));
        return solve(n-1,n,totSum/2,nums,dp);
    }
};