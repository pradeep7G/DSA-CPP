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
    bool topDown(vector<int> &nums){
        int totSum=accumulate(begin(nums),end(nums),0LL);
        int n=nums.size();
        //s1+s2=totSum && s1=s2 ==> s2=totSum/2;
        if(totSum%2)
            return false;
        vector<vector<int>> dp(n,vector<int>(totSum/2 + 1,-1));
        return solve(n-1,n,totSum/2,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int totSum=accumulate(begin(nums),end(nums),0LL);
        int n=nums.size();
        //s1+s2=totSum && s1=s2 ==> s2=totSum/2;
        if(totSum%2)
            return false;
        vector<vector<int>> dp(n,vector<int>(totSum/2 + 1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(nums[0]<=totSum/2)
            dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=0;target<=(totSum/2);target++){
                bool notTake=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target)
                    take=dp[i-1][target-nums[i]];
                dp[i][target]=take || notTake;
            }
        }
        return dp[n-1][totSum/2];
    }
};