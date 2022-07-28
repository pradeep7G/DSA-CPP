class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int k,int target,vector<vector<int>> &dp){
        if(i==0 || target<=0){
            return i==target;
        }
        if(dp[i][target]!=-1)
            return dp[i][target];
        int res=0;
        for(int d=1;d<=k;d++){
            res=(res+solve(i-1,k,target-d,dp))%mod;
        }
        return dp[i][target]=res;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        //try allways;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};