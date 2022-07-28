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
    int memo(int n, int k, int target) {
        //try allways;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
    int numRollsToTarget(int n, int k, int target) {
        //try allways;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int k=j;k<=target;k++){
                    dp[i][k]=(dp[i][k]+dp[i-1][k-j])%mod;
                }
            }
        }
        return dp[n][target];
    }
};